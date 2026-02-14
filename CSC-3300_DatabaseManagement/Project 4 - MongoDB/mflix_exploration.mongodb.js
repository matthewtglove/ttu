use('sample_mflix');

// db.users.aggregate([
//   {
//     $lookup: {
//       from: "comments",
//       localField: "email",
//       foreignField: "email",
//       as: "temp"
//     }
//   },
//   {
//     $project: {
//       _id: 0,
//       email: 1,
//       "temp.text": 1
//     }
//   }
// ]);

db.users.find();

// db.movies.aggregate([
//     {
//     $project: {
//         title: 1
//     }
//     }
// ])

// db.movies.aggregate([
//     {
//     $project: {
//         _id: 0,
//         title: 1
//     }
//     }
// ])

// db.movies.find(
//     { title: { $exists: true } },
//     { _id: 0 }
// )

// db.movies.find(
//     { title: { $exists: true } },
//     { _id: 0, title: 1 }
// )
