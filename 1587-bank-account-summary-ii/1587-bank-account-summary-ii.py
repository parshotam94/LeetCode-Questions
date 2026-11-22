import pandas as pd

def account_summary(users: pd.DataFrame, transactions: pd.DataFrame) -> pd.DataFrame:
    groups=transactions.groupby('account')['amount'].sum()
    merged=pd.merge(groups, users, on='account', how='left')
    merged=merged.rename(columns={'amount': 'balance'})
    res=merged[merged['balance']>10000]
    return res[['name','balance']]
    