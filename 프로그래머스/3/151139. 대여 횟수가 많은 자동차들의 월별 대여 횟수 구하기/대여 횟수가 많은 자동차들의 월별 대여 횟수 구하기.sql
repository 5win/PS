-- 코드를 입력하세요

select month(h1.start_date) as 'month', car_id, count(1) as 'records'
from car_rental_company_rental_history as h1
where h1.car_id in (select car_id
                  from car_rental_company_rental_history as h2
                  -- where h2.start_date between '2022-08-01' and '2022-10-31'
                  where month(h2.start_date) between 8 and 10
                  group by h2.car_id
                  having count(h2.car_id) >= 5)
                  and
                  month(h1.start_date) between 8 and 10
-- group by date_format(h1.start_date, '%m'), car_id
group by month, h1.car_id
order by month asc, h1.car_id desc