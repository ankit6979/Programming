WITH DistinctConversation AS (
  SELECT DISTINCT
    SENDER_ID,
    RECEIVER_ID
  FROM playground.messenger
),
ConversationThreads AS (
  SELECT
    T1.SENDER_ID AS T1_SID,
    T2.SENDER_ID AS T2_SID,
    T1.RECEIVER_ID AS T1_RID,
    T2.RECEIVER_ID AS T2_RID
  FROM DistinctConversation T1
  JOIN DistinctConversation T2
  ON 
    (T1.SENDER_ID = T2.RECEIVER_ID AND T1.RECEIVER_ID = T2.SENDER_ID)
)
SELECT
  (SELECT COUNT(*) FROM playground.messenger) - ((( SELECT COUNT(*) FROM playground.messenger ) - ( SELECT COUNT(*) FROM DistinctConversation )) + ( SELECT COUNT(*) / 2 FROM ConversationThreads ))
   AS count


''' Optimized '''
WITH NormalizedConversation AS (
  SELECT DISTINCT
    LEAST(SENDER_ID, RECEIVER_ID) AS user1,
    GREATEST(SENDER_ID, RECEIVER_ID) AS user2
  FROM playground.messenger
)
SELECT
    -- (SELECT COUNT(*) FROM playground.messenger) AS raw_count,
    (SELECT COUNT(*) FROM NormalizedConversation) AS unique_conversation_count,
    -- (SELECT COUNT(*) FROM playground.messenger) 
      -- - (SELECT COUNT(*) FROM NormalizedConversation) AS difference;
-- LEAST(SENDER_ID, RECEIVER_ID) puts the smaller ID in user1.

-- GREATEST(SENDER_ID, RECEIVER_ID) puts the larger ID in user2.