// 355. Design Twitter
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

class Twitter {

  private static class Tweet {
    int id, time;
    Tweet next;

    public Tweet(int id, int time, Tweet nextTweet) {
      this.id = id;
      this.time = time;
      this.next = nextTweet;
    }
  }

  private static int timestamp = 0; // global time
  private Map<Integer, Tweet> tweets;
  private Map<Integer, Set<Integer>> follows;

  public Twitter() {
    tweets = new HashMap<>();
    follows = new HashMap<>();
  }

  // Post a new tweet
  public void postTweet(int userId, int tweetId) {
    timestamp++;
    Tweet head = tweets.get(userId);
    Tweet newTweet = new Tweet(tweetId, timestamp, head);
    tweets.put(userId, newTweet);

    // self-follow
    follow(userId, userId);
  }

  public List<Integer> getNewsFeed(int userId) {
    List<Integer> feed = new ArrayList<>();
    if (!follows.containsKey(userId))
      return feed;

    // Max-Heap
    PriorityQueue<Tweet> pq = new PriorityQueue<>((a, b) -> b.time - a.time);

    for (int followee : follows.get(userId)) {
      if (tweets.containsKey(followee) && tweets.get(followee) != null) {
        pq.offer(tweets.get(followee));
      }
    }

    while (!pq.isEmpty() && feed.size() < 10) {
      Tweet top = pq.poll();
      feed.add(top.id);

      if (top.next != null)
        pq.offer(top.next);
    }
    return feed;
  }

  // Follower follows followee
  public void follow(int followerId, int followeeId) {
    follows.putIfAbsent(followerId, new HashSet<>());
    follows.get(followerId).add(followeeId);
    // self-follow always
    follows.get(followerId).add(followerId);
  }

  // Follower unfollows followee
  public void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;

    if (follows.containsKey(followerId)) {
      follows.get(followerId).remove(followeeId);
      // keep self-follow
      follows.get(followerId).add(followerId);
    }
  }

  public static void main(String[] args) {
    Twitter twitter = new Twitter();

    twitter.postTweet(1, 5); // User 1 posts tweet 5
    System.out.println("Feed of user 1: " + twitter.getNewsFeed(1));
    // Expected: [5]

    twitter.follow(1, 2); // User 1 follows user 2
    twitter.postTweet(2, 6); // User 2 posts tweet 6
    System.out.println("Feed of user 1 after following user 2: " + twitter.getNewsFeed(1));
    // Expected: [6, 5]

    twitter.unfollow(1, 2); // User 1 unfollows user 2
    System.out.println("Feed of user 1 after unfollowing user 2: " + twitter.getNewsFeed(1));
    // Expected: [5]
  }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */