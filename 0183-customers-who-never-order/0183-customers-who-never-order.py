import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    res=customers.merge(orders, how='left', left_on='id', right_on='customerId')
    mask=res['customerId'].isna()
    res_df=res[mask]
    res_df=res_df[['name']].rename(columns={'name': 'Customers'})
    return res_df
    