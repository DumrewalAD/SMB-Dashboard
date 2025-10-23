
q = f"""
(
with users_data_month_on_month as 
    (
    select stripe_customer_id, user_id, user_status, user_email, user_created_date
                  , date(date_trunc('month', user_created_date)) as user_created_month
                  , count(distinct date(date_trunc('month', session_date))) as subscriptions_months_count
                  , min(date(date_trunc('day', session_date))) first_susbscribed_day
                  , min(date(date_trunc('month', session_date))) first_susbscribed_month
    
                  , min(case when period = 'year' then date(date_trunc('month', session_date)) end) as first_yearly_subscription_date
                  , max(case when period = 'year' then date(date_trunc('month', session_date)) end) as latest_yearly_subscription_date
 
                  , max(case when date(date_trunc('month', session_date)) = '2022-05-01' then 1 else 0 end) as "2022-05"
                  , max(case when date(date_trunc('month', session_date)) = '2022-06-01' then 1 else 0 end) as "2022-06"
                  , max(case when date(date_trunc('month', session_date)) = '2022-07-01' then 1 else 0 end) as "2022-07"
                  , max(case when date(date_trunc('month', session_date)) = '2022-08-01' then 1 else 0 end) as "2022-08"
                  , max(case when date(date_trunc('month', session_date)) = '2022-09-01' then 1 else 0 end) as "2022-09"
                  , max(case when date(date_trunc('month', session_date)) = '2022-10-01' then 1 else 0 end) as "2022-10"
                  , max(case when date(date_trunc('month', session_date)) = '2022-11-01' then 1 else 0 end) as "2022-11"
                  , max(case when date(date_trunc('month', session_date)) = '2022-12-01' then 1 else 0 end) as "2022-12"
                  
                  , max(case when date(date_trunc('month', session_date)) = '2023-01-01' then 1 else 0 end) as "2023-01"
                  , max(case when date(date_trunc('month', session_date)) = '2023-02-01' then 1 else 0 end) as "2023-02"
                  , max(case when date(date_trunc('month', session_date)) = '2023-03-01' then 1 else 0 end) as "2023-03"
                  , max(case when date(date_trunc('month', session_date)) = '2023-04-01' then 1 else 0 end) as "2023-04"
                  , max(case when date(date_trunc('month', session_date)) = '2023-05-01' then 1 else 0 end) as "2023-05"
                  , max(case when date(date_trunc('month', session_date)) = '2023-06-01' then 1 else 0 end) as "2023-06"
                  , max(case when date(date_trunc('month', session_date)) = '2023-07-01' then 1 else 0 end) as "2023-07"
                  , max(case when date(date_trunc('month', session_date)) = '2023-08-01' then 1 else 0 end) as "2023-08"
                  , max(case when date(date_trunc('month', session_date)) = '2023-09-01' then 1 else 0 end) as "2023-09"
                  , max(case when date(date_trunc('month', session_date)) = '2023-10-01' then 1 else 0 end) as "2023-10"
                  , max(case when date(date_trunc('month', session_date)) = '2023-11-01' then 1 else 0 end) as "2023-11"
                  , max(case when date(date_trunc('month', session_date)) = '2023-12-01' then 1 else 0 end) as "2023-12"
                  
                  , max(case when date(date_trunc('month', session_date)) = '2024-01-01' then 1 else 0 end) as "2024-01"
                  , max(case when date(date_trunc('month', session_date)) = '2024-02-01' then 1 else 0 end) as "2024-02"
                  , max(case when date(date_trunc('month', session_date)) = '2024-03-01' then 1 else 0 end) as "2024-03"
                  , max(case when date(date_trunc('month', session_date)) = '2024-04-01' then 1 else 0 end) as "2024-04"
                  , max(case when date(date_trunc('month', session_date)) = '2024-05-01' then 1 else 0 end) as "2024-05"
                  , max(case when date(date_trunc('month', session_date)) = '2024-06-01' then 1 else 0 end) as "2024-06"
                  , max(case when date(date_trunc('month', session_date)) = '2024-07-01' then 1 else 0 end) as "2024-07"
                  , max(case when date(date_trunc('month', session_date)) = '2024-08-01' then 1 else 0 end) as "2024-08"
                  , max(case when date(date_trunc('month', session_date)) = '2024-09-01' then 1 else 0 end) as "2024-09"
                  , max(case when date(date_trunc('month', session_date)) = '2024-10-01' then 1 else 0 end) as "2024-10"
                  , max(case when date(date_trunc('month', session_date)) = '2024-11-01' then 1 else 0 end) as "2024-11"
                  , max(case when date(date_trunc('month', session_date)) = '2024-12-01' then 1 else 0 end) as "2024-12"
                  
                  , max(case when date(date_trunc('month', session_date)) = '2025-01-01' then 1 else 0 end) as "2025-01"
                  , max(case when date(date_trunc('month', session_date)) = '2025-02-01' then 1 else 0 end) as "2025-02"
                  , max(case when date(date_trunc('month', session_date)) = '2025-03-01' then 1 else 0 end) as "2025-03"
                  , max(case when date(date_trunc('month', session_date)) = '2025-04-01' then 1 else 0 end) as "2025-04"
                  , max(case when date(date_trunc('month', session_date)) = '2025-05-01' then 1 else 0 end) as "2025-05"
                  , max(case when date(date_trunc('month', session_date)) = '2025-06-01' then 1 else 0 end) as "2025-06"
                  , max(case when date(date_trunc('month', session_date)) = '2025-07-01' then 1 else 0 end) as "2025-07"
                  , max(case when date(date_trunc('month', session_date)) = '2025-08-01' then 1 else 0 end) as "2025-08"
                  , max(case when date(date_trunc('month', session_date)) = '2025-09-01' then 1 else 0 end) as "2025-09"
                  , max(case when date(date_trunc('month', session_date)) = '2025-10-01' then 1 else 0 end) as "2025-10"
    from user_cross_active_session_date_with_plan
    join 
        (
        select distinct stripe_customer_id, user_id, user_status
        from read_csv_auto('{(prod_data_2025 / "mentalyc_mentalyc_users.csv").as_posix()}')
        where user_type = 'therapist' 
        ) users_table
        using(user_id)
    group by 1, 2, 3, 4, 5, 6
    )
    
, yearly_subscription_data as 
    (
    select * 
    from 
        (
        select user_id, count(distinct stripe_subscription_id) as subs_ids, max(latest_subscription_date) as latest_subscription_date, max(latest_cancel_date) as latest_cancel_date
                      , max(isLatestYearlySubscriptionCanceled) as isLatestYearlySubscriptionCanceled
                      , max(isYearlySubscriber) as isYearlySubscriber
        from 
            (
            select distinct user_id, stripe_subscription_id, latest_subscription_date, latest_cancel_date
                                   , case when latest_cancel_date>latest_subscription_date then 1 else 0 end as  isLatestYearlySubscriptionCanceled
                                   , case when latest_subscription_date >= current_date-interval'1'year then 1 else 0 end as isYearlySubscriber
            from 
                (
                select distinct user_id, stripe_subscription_id, max(to_timestamp(timestamp/1000)) as latest_subscription_date 
                from read_csv_auto('{(prod_data_2025 / "mentalyc_subscription_events.csv").as_posix()}') 
                    join 
                    (
                    select distinct user_id 
                    from read_csv_auto('{(prod_data_2025 / "mentalyc_subscription_events.csv").as_posix()}') 
                    where period = 'year'
                    ) a 
                    using(user_id)
                where amount>0 and period = 'year'
                group by 1, 2
                ) a 
                left join 
                (
                select distinct user_id, stripe_subscription_id, max(to_timestamp(timestamp/1000)) as latest_cancel_date 
                from read_csv_auto('{(prod_data_2025 / "mentalyc_subscription_events.csv").as_posix()}') 
                    join 
                    (
                    select distinct user_id 
                    from read_csv_auto('{(prod_data_2025 / "mentalyc_subscription_events.csv").as_posix()}') 
                    where period = 'year'
                    ) a 
                    using(user_id)
                where event_type = 'canceled' and period = 'year'
                group by 1, 2
                ) b 
                using(user_id, stripe_subscription_id)
            ) c
        group by 1
        )
    )

select *
from 
    (
    select distinct stripe_customer_id as customerId, user_email as email, user_created_date as createdAt, first_susbscribed_month as joinMonth 
                      , subscriptions_months_count as subscriptionsCount
                      , first_yearly_subscription_date as firstYearlySubscriptionDate, latest_yearly_subscription_date as latestYearlySubscriptionEndDate
                      , islatestyearlysubscriptioncanceled as isLatestYearlySubscriptionCanceled, isyearlysubscriber as isYearlySubscriber
                      , 'FALSE' as wasOnTeam, 'null' as teamStartDate, 'null' as teamEndDate
        
                      , "2022-05", "2022-06", "2022-07", "2022-08", "2022-09", "2022-10", "2022-11", "2022-12"
                      , "2023-01", "2023-02", "2023-03", "2023-04", "2023-05", "2023-06", "2023-07", "2023-08", "2023-09", "2023-10", "2023-11", "2023-12"
                      , "2024-01", "2024-02", "2024-03", "2024-04", "2024-05", "2024-06", "2024-07", "2024-08", "2024-09", "2024-10", "2024-11", "2024-12"
                      , "2025-01", "2025-02", "2025-03", "2025-04", "2025-05", "2025-06", "2025-07", "2025-08", "2025-09", "2025-10"
    from users_data_month_on_month
    left join yearly_subscription_data using(user_id)
    )
)
"""
sample = duckdb.sql(q).df()
sample
sample.to_csv("/Users/adarshdumrewal/Desktop/customer_profile_data_20th_oct.csv", index=False)
