import numpy as np
import pandas as pd
from scipy.stats import chi2

probs = [0.005, 0.01, 0.025, 0.05, 0.10, 0.20, 0.80, 0.90, 0.95, 0.975, 0.99, 0.995]
rs = range(1, 11)

rows = []
for r in rs:
    row = [chi2.ppf(p, df = r) for p in probs]
    rows.append(row)

df = pd.DataFrame(rows, index=rs, columns=probs)
df.index.name = 'r'
df_rounded = df.round(4)
df_rounded.to_csv('chi2_table_r1_to_10.csv')
print(df_rounded)
