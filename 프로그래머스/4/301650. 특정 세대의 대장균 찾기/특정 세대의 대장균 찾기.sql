WITH fir AS(
    select id
    from ECOLI_DATA
    where parent_id IS NULL
),
sec AS(
    select b.id
    from ECOLI_DATA as b
    join fir on b.PARENT_ID=fir.ID
)


select a.id
from ECOLI_DATA as a
join sec on a.PARENT_ID=sec.id
order by a.ID
