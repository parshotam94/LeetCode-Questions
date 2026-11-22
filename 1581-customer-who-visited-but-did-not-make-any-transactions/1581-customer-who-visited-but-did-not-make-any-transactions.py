import pandas as pd

def find_customers(visits: pd.DataFrame, transactions: pd.DataFrame) -> pd.DataFrame:
    joined=pd.merge(visits, transactions, on='visit_id', how='left')
    res=joined[joined['transaction_id'].isna()].groupby('customer_id', as_index=False)['visit_id'].count()
    res.rename(columns={'visit_id': 'count_no_trans'}, inplace=True)
    return res    
    