-- 코드를 작성해주세요
select a.id, a.genotype, b.genotype as PARENT_GENOTYPE
from ECOLI_DATA as a
join ECOLI_DATA as b
on b.id=a.parent_id
where b.genotype&a.genotype=b.genotype
order by a.id
