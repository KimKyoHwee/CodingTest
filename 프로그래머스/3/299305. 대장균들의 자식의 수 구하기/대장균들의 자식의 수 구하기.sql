with child as(
    select PARENT_ID, COUNT(*) as CHILD_COUNT
    from ECOLI_DATA
    where PARENT_ID is not null
    group by PARENT_ID
    order by PARENT_ID
)
select a.ID, IFNULL(b.CHILD_COUNT, 0) as CHILD_COUNT
from ECOLI_DATA as a
left join child as b
on a.ID=b.PARENT_ID
order by a.ID