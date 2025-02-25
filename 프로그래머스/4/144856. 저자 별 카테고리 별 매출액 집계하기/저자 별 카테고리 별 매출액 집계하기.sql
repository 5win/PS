-- select b.author_id, a.author_name, b.category, (b.price * if(bs.total_sum is null, 0, bs.total_sum)) as total_sales



select c.author_id, c.author_name, c.category, sum(c.each_sales) as total_sales
from (select b.author_id, a.author_name, b.category, b.price * bs.total_sum as each_sales
    from book as b 
                inner join author as a on b.author_id = a.author_id
                left join(select book_id, sum(sales) as total_sum
                          from book_sales
                          where date_format(sales_date, '%Y-%m') = '2022-01'
                          group by book_id) as bs
                on b.book_id = bs.book_id
      ) as c
group by c.author_id, c.category
order by c.author_id asc, c.category desc