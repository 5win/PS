-- 코드를 입력하세요

select warehouse_id, warehouse_name, address, (case 
                                               when freezer_yn is null
                                               then 'N'
                                               else freezer_yn
                                               end) as freezer_yn
from food_warehouse
where address like '경기도%'