from scipy.stats import norm

# Parameters
mu = 55          # mean of exam scores
sigma = 10.5        # standard deviation
grade_percentages = {
    'A': 0.10,
    'B': 0.10,
    'C': 0.60,
    'D': 0.08,
    'F': 0.12
}

# Step 1: Compute cumulative probabilities from lowest grade
cumulative_probs = []
total = 0
for grade in ['F', 'D', 'C', 'B', 'A']:  # from lowest to highest
    total += grade_percentages[grade]
    cumulative_probs.append((grade, total))

# Step 2: Find cutoffs using inverse CDF (percent point function)
cutoffs = {}
for i in range(len(cumulative_probs) - 1):  # ignore A, since it's the top
    grade = cumulative_probs[i][0]
    cum_prob = cumulative_probs[i][1]
    cutoff = norm.ppf(cum_prob, loc=mu, scale=sigma)
    cutoffs[grade] = cutoff

# Step 3: Print results
print("Grade Cutoffs:")
for grade in ['F', 'D', 'C', 'B']:
    print(f"{grade} / next grade cutoff: {cutoffs[grade]:.2f}")
