import matplotlib.pyplot as plt
import numpy as np

from matplotlib import colors
from matplotlib.ticker import PercentFormatter

from sklearn.preprocessing import StandardScaler


N_points = 100000
n_bins = 20

sites = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
         32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61]
richness = [3, 8, 1, 3, 6, 8, 7, 4, 15, 1, 3, 14, 13, 6, 13, 7, 15, 8, 14, 17, 6, 14, 7, 6, 9, 8, 16, 8, 3, 8, 10,
            4, 10, 9, 19, 20, 15, 19, 4, 13, 14, 12, 9, 20, 2, 13, 11, 8, 12, 14, 12, 11, 3, 7, 9, 21, 17, 17, 3, 12, 7]
abundance = [145, 161, 70, 50, 140, 131, 204, 98, 287, 15, 11, 311, 249, 280, 178, 319, 237, 60, 83, 196, 210, 265, 209, 135, 125, 103, 351, 86, 92,
             124, 145, 49, 174, 282, 319, 257, 357, 638, 216, 255, 406, 118, 263, 501, 30, 82, 644, 620, 352, 223, 168, 255, 250, 199, 68, 677, 281, 424, 14, 125, 87]
Shannon_index = [1.084, 1.69, 0, 0.9503, 1.67, 1.538, 1.689, 0.6328, 2.394, 0, 0.9075, 2.36, 1.664, 0.6226, 2.145, 1.074, 1.787, 1.93, 2.227, 2.389, 1.526, 2.256, 1.604, 1.397, 1.509, 1.522, 2.299, 1.561, 0.6488, 1.614,
                 1.984, 1.236, 2.024, 1.05, 2.545, 2.335, 1.904, 2.056, 1.311, 1.517, 2.331, 1.935, 2.059, 2.419, 0.6365, 2.293, 1.861, 1.633, 1.852, 2.414, 2.158, 1.914, 0.4823, 1.704, 1.838, 2.702, 2.446, 2.344, 0.7589, 2.143, 1.623]


# Generate two normal distributions
# dist1 = rng.standard_normal(N_points)
# dist2 = 0.4 * rng.standard_normal(N_points) + 5


fig, axs = plt.subplots(1, 1, sharey=True, tight_layout=True)

# We can set the number of bins with the *bins* keyword argument.
richness = np.array(richness)
scaler = StandardScaler()
richness_normalized = scaler.fit_transform(richness.reshape(-1, 1))
axs.hist(richness_normalized, bins=n_bins)
# axs[1].hist(dist2, bins=n_bins)

plt.show()
