-- 코드를 입력하세요
select p.product_code, (p.price * s.sales_sum) as sales
from product as p
	inner join(select product_id, sum(sales_amount) as sales_sum
              from offline_sale
              group by product_id) as s
         on p.product_id = s.product_id
order by (p.price * s.sales_sum) desc, p.product_code asc
