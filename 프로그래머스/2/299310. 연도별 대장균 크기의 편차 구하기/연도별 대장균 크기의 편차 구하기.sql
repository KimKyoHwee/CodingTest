-- 코드를 작성해주세요
with maximum as(
    select YEAR(DIFFERENTIATION_DATE) as year, MAX(SIZE_OF_COLONY) as colony
    from ECOLI_DATA
    group by YEAR(DIFFERENTIATION_DATE)
)
select YEAR(a.DIFFERENTIATION_DATE) as YEAR, (b.colony-a.SIZE_OF_COLONY) as YEAR_DEV, a.ID
from ECOLI_DATA as a
join maximum as b on YEAR(a.DIFFERENTIATION_DATE)=b.year
order by YEAR, YEAR_DEV