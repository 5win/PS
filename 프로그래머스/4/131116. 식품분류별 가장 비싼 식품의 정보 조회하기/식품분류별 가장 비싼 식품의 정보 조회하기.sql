-- 코드를 입력하세요

select a.category, b.max_price, a.product_name
from food_product as a 
	join (select category, max(price) as max_price
                   from food_product
                   group by category) as b
	on a.category = b.category and a.price = b.max_price
where b.category in ('과자', '국', '김치', '식용유')

order by b. max_price desc