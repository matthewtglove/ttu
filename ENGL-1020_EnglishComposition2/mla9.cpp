/*
https://libguides.csudh.edu/citation/mla

`author1LastName`, `author1FirstName`, and `author2FirstName` `author2LastName`. "`titleOfWork`".
    *`titleOfJournalOrPeriodical`*, `volume`, `no.`, `yearPublished`, `pp`. *`nameOfDatabasae`*, `DOI/URL`

Work from a Preface, **foreword**, introduction, or afterword:
`authorOfForwardLastName`, `authorOfForwardFirstName`. Foreword. *`titleOfBook`*,
    `authorOfBookFirstName` `authorOfBookLastName`, `publisher`, `yearPublished`, `pp`.

Editor, no author named:
`lastName`, `firstName`, and `firstName` `lastName`, editors. *`bookTitle`*. `publisher`, `yearPublished`.

**Article** in a print journal:
`lastName`, `firstName`. "`articleTitle`". `journalName`, `vol`, `no.`, `yearPublished`, `pp`.

Ebook:
`lastName`, `firstName`. *`titleOfBook`*. E-book ed., `publisher`, `yearPublished`, `(pp)`.

Audiobook:
`lastName`, `firstName`. *`titleOfBook`*. `narratorFirstLastName`, audiobook ed., `publisher`, `yearPublished`, `(pp)`.

Website:
`authorLastFirstName`. "`titleOfWork`". *`titleOfWebsite`*, `dataPublishedOrAccessDate`, `DOI/URL`


## Citing books
`lastName`, `firstName`. *`bookTitle`*. `publisher`, `yearOfPublish`.

**Author and editor are both named:**
`lastName`, `firstName`. *`bookTitle`*. Edited by `firstName lastName` `publisher`, `yearOfPublish`.

**Only editor's contribution:**
`lastNameOfEditor`, `firstNameOfEditor`, editor. *`bookTitle`*. By author `firstName lastName` `publisher`, `yearOfPublish`.

**A translated book:**
`lastName`, `firstName`. *`bookTitle`*. Translated by `firstName lastName` `publisher`, `yearOfPublish`.

**Republication of a book (modern edition):**
`lastName`, `firstName`. *`bookTitle`*. `originalRearOfPublish`. `publisher`, `newYearOfPublish`.

**Multiple publishers listed:**
`lastName`, `firstName`. *`bookTitle`*. `publisher1` / `publisher2`, `yearOfPublish`.

**If a book has a title within the title:**
`lastName`, `firstName`. *`bookTitle`*`titleWithinBookTitle`. `publisher`, `yearOfPublish`.
- Just italicize the whole title of the book except the part that is the other book's title

**A book with a short title:**
`lastName`, `firstName`. *"`shortWorkTitle`" `restOfBookTitle`*. `publisher`, `yearOfPublish`.
- A short work is something within another work, like an article within a bigger study or a song within an album
- A long work is its own independent thing
*/

// Make this in JS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // Standard print book
    string lastName;
    string firstName;
    string bookName;
    string publisher;
    string yearOfPublish;

    getline(cin, lastName);
    getline(cin, firstName);
    getline(cin, bookName);
    getline(cin, publisher);
    getline(cin, yearOfPublish);

    cout << lastName << ", " << firstName << ". *" << bookName << "*. " << publisher << ", " << yearOfPublish << "." << endl;
}