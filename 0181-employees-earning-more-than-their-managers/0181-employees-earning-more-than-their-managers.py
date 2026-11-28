import pandas as pd

def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    res=employee.merge(employee, how='left', left_on='managerId', right_on='id')
    filtered_res=res.query('salary_x>salary_y')
    res_df=pd.DataFrame({'Employee': filtered_res['name_x']})
    return res_df

    