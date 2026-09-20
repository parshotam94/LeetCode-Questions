# Write your MySQL query statement below
with ranked as(
    select score, dense_rank() over(
        order by score desc
    ) as `rank` from Scores
) select score, `rank` from ranked;