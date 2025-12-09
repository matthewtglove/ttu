use('sample_mflix');
/* q1 
Consider the movies collection in the sample_mflix database.
Each movie document contains a genres array.
Write an aggregation query that determines which genres appear most frequently.
Return the top five genres together with the number of movies in each genre.

Your output should follow the structure shown in the sample output below.
The numbers shown are only examples. 

[
  { "genre": "Drama", "count": 9215 },
  { "genre": "Comedy", "count": 6542 },
  { "genre": "Action", "count": 4120 },
  { "genre": "Thriller", "count": 3985 },
  { "genre": "Adventure", "count": 3127 }
]
*/
use('sample_mflix');
db.movies.aggregate([
  { $unwind: "$genres" },
  { $group: { _id: "$genres", count: { $sum: 1 } } },
  { $sort: { count: -1 } },
  { $limit: 5 },
  { $project: { _id: 0, genre: "$_id", count: 1 } }
]);

/* q2 
Consider the users and comments collections in the sample_mflix database.
Each document in comments includes an email field that is intended to correspond to the email field in users.

Write an aggregation query on the users collection that returns, for each user, the number of comments they have written.
Your output should list the user’s name, email, and their total comment count, and then return only the 10 users with the highest number of comments.

Your output should follow the structure shown in the sample output below.
The numbers shown are only examples.

[
  { "name": "John Doe",       "email": "john@example.com",       "commentCount": 128 },
  { "name": "Mary Johnson",   "email": "maryj@example.com",      "commentCount": 117 },
  { "name": "Alice Walker",   "email": "alicew@example.com",     "commentCount": 109 },
  { "name": "Daniel Roberts", "email": "droberts@example.com",   "commentCount": 102 },
  { "name": "Linda Smith",    "email": "lindas@example.com",     "commentCount": 98 },
  { "name": "Kevin Lee",      "email": "klee@example.com",       "commentCount": 95 },
  { "name": "Robert Chen",    "email": "rchen@example.com",      "commentCount": 92 },
  { "name": "Emma Davis",     "email": "emdavis@example.com",    "commentCount": 90 },
  { "name": "Michael Park",   "email": "mpark@example.com",      "commentCount": 87 },
  { "name": "Sophia Miller",  "email": "smiller@example.com",    "commentCount": 84 }
]
*/
use('sample_mflix');
db.users.aggregate([
  {
    $lookup: {
      from: "comments",
      localField: "email",
      foreignField: "email",
      as: "user_comments"
    }
  },
  {
    $project: {
      name: 1,
      email: 1,
      commentCount: { $size: "$user_comments" }
    }
  },
  { $sort: { commentCount: -1 } },
  { $limit: 10 }
]);

/* q3
Consider the movies collection in the sample_mflix database.
Each movie document contains a year field and an embedded imdb document with a numeric rating field.

Write an aggregation query on the movies collection that groups movies by their year of release, computes the average IMDb rating for each year, and returns the results sorted by year.

Your output should follow the structure shown in the sample output below.
The numbers shown are only examples.

[
  { "year": 1920, "averageRating": 6.4,  "movieCount": 12 },
  { "year": 1921, "averageRating": 6.7,  "movieCount": 18 },
  { "year": 1922, "averageRating": 6.9,  "movieCount": 21 },
  { "year": 1923, "averageRating": 6.5,  "movieCount": 17 },
  { "year": 1924, "averageRating": 6.8,  "movieCount": 19 }
]
*/
use('sample_mflix');
db.movies.aggregate([
  {
    $group: {
      _id: "$year",
      averageRating: { $avg: "$imdb.rating" },
      movieCount: { $sum: 1 }
    }
  },
  {
    $project: {
      _id: 0,
      year: "$_id",
      averageRating: { $round: ["$averageRating", 1] },
      movieCount: 1
    }
  },
  { $sort: { year: 1 } }
]);

/* q4
Consider the comments and movies collections in the sample_mflix database.
Each document in comments contains a movie_id field that is intended to match the _id field in movies.

Write an aggregation query on the comments collection that determines how many comments reference a valid movie.
A comment should be counted only if its movie_id matches an existing movie document in the movies collection.

Your output should follow the structure shown in the sample output below.
The number shown is only an example.

[
  { "comments_with_matching_movie": 22134 }
]
*/
use('sample_mflix');
db.comments.aggregate([
  {
    $lookup: {
      from: "movies",
      localField: "movie_id",
      foreignField: "_id",
      as: "matched_movie"
    }
  },
  {
    $match: {
      matched_movie: { $ne: [] }
    }
  },
  {
    $count: "comments_with_matching_movie"
  }
]);

/* q5
Consider the comments and movies collections in the sample_mflix database.
Each document in comments contains a movie_id field that is intended to match the _id field in movies.

Write an aggregation query on the comments collection that finds the 10 movies released in or after the year 2000 that have the highest number of comments.

Your output should list, for each such movie:
- the movie’s title,
- its year of release, and
- the total number of comments it has received.

Your output should follow the structure shown in the sample output below.
The numbers shown are only examples.

  { "title": "Movie A", "year": 2005, "commentCount": 143 },
  { "title": "Movie B", "year": 2012, "commentCount": 137 },
  { "title": "Movie C", "year": 2008, "commentCount": 129 },
  { "title": "Movie D", "year": 2015, "commentCount": 122 },
  { "title": "Movie E", "year": 2003, "commentCount": 118 },
  { "title": "Movie F", "year": 2011, "commentCount": 112 },
  { "title": "Movie G", "year": 2007, "commentCount": 109 },
  { "title": "Movie H", "year": 2010, "commentCount": 103 },
  { "title": "Movie I", "year": 2004, "commentCount": 99 },
  { "title": "Movie J", "year": 2009, "commentCount": 95 }
]
*/
use('sample_mflix');
db.comments.aggregate([
  {
    $lookup: {
      from: "movies",
      localField: "movie_id",
      foreignField: "_id",
      as: "movie_info"
    }
  },
  { $unwind: "$movie_info" },
  { $match: { "movie_info.year": { $gte: 2000 } } },
  {
    $group: {
      _id: { title: "$movie_info.title", year: "$movie_info.year" },
      commentCount: { $sum: 1 }
    }
  },
  { $sort: { commentCount: -1 } },
  { $limit: 10 },
  {
    $project: {
      _id: 0,
      title: "$_id.title",
      year: "$_id.year",
      commentCount: 1
    }
  }
]);

/* q6
Consider the movies collection in the sample_mflix database.
Each movie document contains a genres array.

Write an aggregation query that returns, for each genre, the number of movies associated with that genre.
Your output should list:
- the genre name, and
- the total number of movies that include this genre.

Return the genres sorted by number of movies in descending order.

Your output should follow the structure shown in the sample output below.
The numbers shown are only examples.

[
  { "genre": "Drama",    "movieCount": 9215 },
  { "genre": "Comedy",   "movieCount": 6542 },
  { "genre": "Action",   "movieCount": 4120 },
  { "genre": "Thriller", "movieCount": 3985 },
  { "genre": "Adventure","movieCount": 3127 }
]
*/
use('sample_mflix');
db.movies.aggregate([
  { $unwind: "$genres" },
  {
    $group: {
      _id: "$genres",
      movieCount: { $sum: 1 }
    }
  },
  { $sort: { movieCount: -1 } },
  {
    $project: {
      _id: 0,
      genre: "$_id",
      movieCount: 1
    }
  }
]);

/* q7
Consider the movies collection in the sample_mflix database.
Each movie document contains fields such as title and year.

Write an aggregation query that returns the titles of all movies released between 2000 and 2010 inclusive.
Do not return any additional fields.

Your output should follow the structure shown in the sample output below.
The values shown are only examples.

[
  { "title": "Gladiator" },
  { "title": "The Dark Knight" },
  { "title": "Memento" },
  { "title": "Up" }
]
*/
use('sample_mflix');
db.movies.aggregate([
  {
    $match: {
      year: { $gte: 2000, $lte: 2010 }
    }
  },
  {
    $project: {
      _id: 0,
      title: 1
    }
  }
]);

/* q8
Consider the movies collection in the sample_mflix database.
Each movie document contains a genres array.

Write an aggregation query on the movies collection that returns, for movies released in the year 2010, a separate document for each combination of movie and genre.

Your output should list:
- the movie’s title, and
- a single genre value for that document.

In other words, if a movie from 2010 has three genres, it should appear three times in the output, once for each genre.

Your output should follow the structure shown in the sample output below.
The values shown are only examples.

[
  { "title": "Inception",        "genre": "Action" },
  { "title": "Inception",        "genre": "Sci-Fi" },
  { "title": "Inception",        "genre": "Thriller" },
  { "title": "Toy Story 3",      "genre": "Animation" },
  { "title": "Toy Story 3",      "genre": "Comedy" },
  { "title": "Toy Story 3",      "genre": "Family" }
]
*/
use('sample_mflix');
db.movies.aggregate([
  {
    $match: {
      year: 2010
    }
  },
  { $unwind: "$genres" },
  {
    $project: {
      _id: 0,
      title: 1,
      genre: "$genres"
    }
  }
]);

/* q9
Consider the users, comments, and movies collections in the sample_mflix database.
Each document in comments contains:
- an email field intended to match the email field in users, and
- a movie_id field that refers to the _id field of a movie in the movies collection.

Write an aggregation query on the users collection that returns, for each user:
- the user’s name,
- their email, and
- the titles of the movies they have commented on.

Your output should follow the structure shown in the sample output below.
The values shown are only examples.

[
  {
    "name": "John Doe",
    "email": "john@example.com",
    "movieTitles": [
      "Inception",
      "Avatar",
      "The Dark Knight"
    ]
  },
  {
    "name": "Mary Johnson",
    "email": "maryj@example.com",
    "movieTitles": [
      "Up",
      "The Social Network"
    ]
  }
]
*/
use('sample_mflix');
db.users.aggregate([
  {
    $lookup: {
      from: "comments",
      localField: "email",
      foreignField: "email",
      as: "user_comments"
    }
  },
  { $unwind: "$user_comments" },
  {
    $lookup: {
      from: "movies",
      localField: "user_comments.movie_id",
      foreignField: "_id",
      as: "commented_movie"
    }
  },
  { $unwind: "$commented_movie" },
  {
    $group: {
      _id: { name: "$name", email: "$email" },
      movieTitles: { $addToSet: "$commented_movie.title" }
    }
  },
  {
    $project: {
      _id: 0,
      name: "$_id.name",
      email: "$_id.email",
      movieTitles: 1
    }
  }
]);

/* q10
Consider the movies collection in the sample_mflix database.
Each movie document contains a cast array and a directors array.

Write an aggregation query on the movies collection that returns all movies in which at least one director also appears in the cast.

For each such movie, return:
- the movie’s title,
- the full list of actors (the cast array), and
- the full list of directors (the directors array).

Your output should follow the structure shown in the sample output below.
The values shown are only examples.

[
  {
    "title": "Movie A",
    "cast": [
      "Clint Eastwood",
      "Actor One",
      "Actor Two"
    ],
    "directors": [
      "Clint Eastwood"
    ]
  },
  {
    "title": "Movie B",
    "cast": [
      "Ben Affleck",
      "Actor Three",
      "Actor Four"
    ],
    "directors": [
      "Ben Affleck",
      "George Clooney"
    ]
  }
]
*/
use('sample_mflix');
db.movies.aggregate([
  {
    $project: {
      title: 1,
      cast: 1,
      directors: 1,
      commonMembers: {
        $setIntersection: ["$cast", "$directors"]
      }
    }
  },
  {
    $match: {
      commonMembers: { $ne: [] }
    }
  },
  {
    $project: {
      _id: 0,
      title: 1,
      cast: 1,
      directors: 1
    }
  }
]);