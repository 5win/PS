-- 코드를 입력하세요

select a.food_type, a.rest_id, a.rest_name, a.favorites
from rest_info as a inner join (select food_type, max(favorites) as max_f
                          from rest_info
                          group by food_type) as b
				on a.food_type = b.food_type and a.favorites = b.max_f
order by a.food_type desc