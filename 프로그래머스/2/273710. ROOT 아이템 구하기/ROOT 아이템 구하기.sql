with nullid as(
    select item_id
    from ITEM_TREE
    where parent_item_id is null
)
select a.item_id, a.item_name
from ITEM_INFO as a
join nullid on a.item_id=nullid.item_id
order by a.item_id