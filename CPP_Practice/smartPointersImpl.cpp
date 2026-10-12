template <typename T>
class UniqPtr{
    private :
    T* ptr; // raw ptr 
    public: 
    explicit UniqPtr(T* p = nullptr) : ptr(p) {} // constructor
    ~UniqPtr() { delete ptr; } // destructor
    // move constructor
    UniqPtr(UniqPtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr; // release ownership
    }   
    // move assignment operator
    UniqPtr& operator=(UniqPtr&& other) noexcept {
        if (this != &other) {
            delete ptr; // release current resource
            ptr = other.ptr; // transfer ownership
            other.ptr = nullptr; // release ownership from other
        }
        return *this;
    }
    // delete copy constructor and copy assignment operator
    UniqPtr(const UniqPtr&) = delete; // no copy constructor        
    UniqPtr& operator=(const UniqPtr&) = delete; // no copy assignment operator

    T& operator*() { return *ptr; } // dereference operator
    T* operator->() { return ptr; } // arrow operator


}; 

/////////////////////// Cyclic deadlock in shared pointer implementation ///////////////////////

                    #include <iostream>
                    #include <memory>
                    #include <string>

                    struct Student;

                    struct Teacher {
                        std::string name;
                        std::shared_ptr<Student> student; // Teacher holds a shared pointer to Student

                        Teacher(const std::string& n) : name(n) {}
                        ~Teacher() {
                            std::cout << "Teacher " << name << " is being destroyed." << std::endl;
                        }   

                    };

                    struct Student {
                        std::string name;
                        std::shared_ptr<Teacher> teacher; // Student holds a shared pointer to Teacher

                        Student(const std::string& n) : name(n) {}
                        ~Student() {
                            std::cout << "Student " << name << " is being destroyed." << std::endl;
                        }   
                    };

                    void createCyclicReference() {
                        std::shared_ptr<Teacher> teacher = std::make_shared<Teacher>("Mr. Smith");
                        std::shared_ptr<Student> student = std::make_shared<Student>("Alice");

                        teacher->student = student; // Teacher holds a shared pointer to Student
                        student->teacher = teacher; // Student holds a shared pointer to Teacher
                    }       


//////THe fix is Weak_ptr implementation

  {
                    struct Teacher {
                        std::string name;
                        std::shared_ptr<Student> student; // Teacher holds a shared pointer to Student

                        Teacher(const std::string& n) : name(n) {}
                        ~Teacher() {
                            std::cout << "Teacher " << name << " is being destroyed." << std::endl;
                        }   

                    };

                    struct Student {
                        std::string name;
                        std::weak_ptr<Teacher> teacher; // Student holds a weak pointer to Teacher

                        Student(const std::string& n) : name(n) {}
                        ~Student() {
                            std::cout << "Student " << name << " is being destroyed." << std::endl;
                        }   
                    };

                    void fixCyclicReference() {
                        std::shared_ptr<Teacher> teacher = std::make_shared<Teacher>("Mr. Smith");
                        std::shared_ptr<Student> student = std::make_shared<Student>("Alice");

                        teacher->student = student; // Teacher holds a shared pointer to Student
                        student->teacher = teacher; // Student holds a weak pointer to Teacher
                    }

                };

/*

Key Takeaways
Use shared_ptr for "Parent-to-Child" relationships (ownership).

Use weak_ptr for "Child-to-Parent" or "Back-links" to break cycles.

Always .lock() a weak_ptr before using it. This returns a shared_ptr if the object is still alive, ensuring thread safety during access.
*/