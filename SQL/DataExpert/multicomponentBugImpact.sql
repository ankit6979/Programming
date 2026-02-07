WITH affectedComponenets AS (
    SELECT
        component_id,
        COUNT(bug_num) AS bugs_in_component
    FROM playground.bug_component
    GROUP BY 1
),
affectedComponenetstIitle AS (
    SELECT
        component_id,
        title AS component_title,
        bugs_in_component
    FROM affectedComponenets
    LEFT JOIN playground.component AS comp
        ON affectedComponenets.component_id = comp.id
),
bugsInComponent AS (
    SELECT
        bug_num
    FROM playground.bug_component
    GROUP BY 1 
    HAVING COUNT(1) > 1
),
bugsInComponentTitle AS (
    SELECT
        bug_num,
        title AS bug_title
    FROM bugsInComponent
    LEFT JOIN playground.bug AS bug
        ON bugsInComponent.bug_num = bug.num
)
SELECT
    bug_title,
    component_title,
    bugs_in_component
FROM bugsInComponentTitle
LEFT JOIN playground.bug_component AS bug_component
    ON bugsInComponentTitle.bug_num = bug_component.bug_num
LEFT JOIN affectedComponenetstIitle
    ON affectedComponenetstIitle.component_id = bug_component.component_id
ORDER BY bugs_in_component DESC, bug_title ASC