
#%%
import numpy as np
import pandas as pd

# %%

df = pd.read_csv(r"06 - Updated.csv")
df.head()
# %%

df = df[['sub_mssg']]
df.head()
# %%

df.to_csv("Data for Tf Idf.csv",index=False,header=False)

# %%
