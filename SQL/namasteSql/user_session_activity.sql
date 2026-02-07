WITH event_with_diff AS (
    SELECT
    userid,
    event_time,
    LAG(event_time) OVER (PARTITION BY userid ORDER BY event_time ASC) AS prev_event_time,
    TIMESTAMPDIFF(
        MINUTE,
        LAG(event_time) OVER (PARTITION BY userid ORDER BY event_time ASC),
        event_time
    ) AS minutes_diff
    FROM events
),
session_flags AS (
    select
        userid,
        minutes_diff,
        event_time,
        prev_event_time,
        case
            when minutes_diff is null or minutes_diff > 30 then 1
            else 0
        end as new_session_flag
    from event_with_diff
),
session_id_data as (
	select
		userid,
		event_time,
		prev_event_time,
		minutes_diff,
		sum(new_session_flag) over(partition by userid order by event_time) as session_id
	from session_flags
),
user_activity_data as (
    select
        userid,
        session_id,
        min(event_time) as session_start_time,
        max(event_time) as session_end_time,
        count(1) as event_count
    from session_id_data
    group by 1,2
)
select
    userid,
    session_id,
    session_start_time,
    session_end_time,
    TIMESTAMPDIFF (minute, session_start_time, session_end_time) as session_duration,
    event_count
from user_activity_data