use('sample_mflix');
console.log(db.getCollectionNames());


// db.movies.findOne();


db.movies.find({type: "movie"});





console.log(db.movies.find({type: "movie"}));

console.log(db.movies.countDocuments());
console.log(db.comments.countDocuments());
console.log(db.sessions.countDocuments());
console.log(db.embedded_movies.countDocuments());
console.log(db.theaters.countDocuments());
console.log(db.users.countDocuments());


//db.comments.findOne();


db.comments.aggregate([
    {
        $lookup: {
          from: "movies",
          localField: "movie_id",
          foreignField: "_id",
          as: "movie"
        }
    }
])

db.users.findOne();

db.movies.countDocuments({rated :{$exists: true}});


db.movies.aggregate([
{ $project: { fields: { $objectToArray: "$$ROOT" } } },
{ $unwind: "$fields" },
{ $group: { _id: null, allFields: { $addToSet: "$fields.k" } } }
])