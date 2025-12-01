CREATE DATABASE DavesDVDs;

USE DavesDVDs;

SHOW TABLES;

CREATE TABLE
    Staff (
        staffId VARCHAR(8) NOT NULL,
        name VARCHAR(255),
        position VARCHAR(255),
        salary NUMERIC(9, 0) CHECK (salary > 0),
        PRIMARY KEY (staffId)
    );

CREATE TABLE
    Branch (
        branchId VARCHAR(8) NOT NULL,
        phoneNumber VARCHAR(10),
        street VARCHAR(255),
        city VARCHAR(255),
        state VARCHAR(255),
        zipCode VARCHAR(10),
        managerId VARCHAR(8) NOT NULL,
        PRIMARY KEY (branchId),
        -- We don't want to allow deleting of a staff member who is managing a branch
        FOREIGN KEY (managerId) REFERENCES Staff (staffId) ON DELETE RESTRICT
    );

CREATE TABLE
    Works_For (
        staffId VARCHAR(8) NOT NULL,
        branchId VARCHAR(8) NOT NULL,
        startDate DATE NOT NULL,
        endDate DATE,
        PRIMARY KEY (staffId, branchId, startDate),
        FOREIGN KEY (branchId) REFERENCES Branch (branchId) ON DELETE CASCADE,
        FOREIGN KEY (staffId) REFERENCES Staff (staffId) ON DELETE CASCADE
    );

CREATE TABLE
    DVD (
        catalogId VARCHAR(8) NOT NULL,
        title VARCHAR(255),
        category VARCHAR(255) CHECK (
            category IN (
                'Action',
                'Adult',
                'Children',
                'Drama',
                'Horror',
                'Sci-Fi',
            )
        ),
        director VARCHAR(255),
        dailyRental numeric(5, 2) CHECK (dailyRental > 0),
        PRIMARY KEY (catalogId)
    );

CREATE TABLE
    Actor (
        catalogId VARCHAR(8) NOT NULL,
        name VARCHAR(255) NOT NULL,
        PRIMARY KEY (catalogId, name),
        FOREIGN KEY (catalogId) REFERENCES DVD (catalogId) ON DELETE CASCADE
    );

CREATE TABLE
    DVD_Copy (
        dvdCopyId VARCHAR(8) NOT NULL,
        branchId VARCHAR(8) NOT NULL,
        catalogId VARCHAR(8) NOT NULL,
        -- TODO: Derive status (if it is rented or available) from Rental table
        PRIMARY KEY (dvdCopyId),
        FOREIGN KEY (branchId) REFERENCES Branch (branchId) ON DELETE CASCADE,
        FOREIGN KEY (catalogId) REFERENCES DVD (catalogId) ON DELETE CASCADE
    );

CREATE TABLE
    Member (
        memberId VARCHAR(8) NOT NULL,
        firstName VARCHAR(255),
        lastName VARCHAR(255),
        phoneNumber VARCHAR(10),
        city VARCHAR(255),
        street VARCHAR(255),
        state VARCHAR(255),
        zipCode VARCHAR(10),
        branchId VARCHAR(8) NOT NULL,
        registeredDate DATE NOT NULL,
        PRIMARY KEY (memberId),
        FOREIGN KEY (branchId) REFERENCES Branch (branchId) ON DELETE CASCADE
    );

CREATE TABLE
    Rental (
        rentalId VARCHAR(8) NOT NULL,
        rentDate DATE NOT NULL,
        returnDate DATE,
        dvdCopyId VARCHAR(8) NOT NULL,
        memberId VARCHAR(8) NOT NULL,
        PRIMARY KEY (rentalId),
        FOREIGN KEY (dvdCopyId) REFERENCES DVD_Copy (dvdCopyId) ON DELETE CASCADE,
        FOREIGN KEY (memberId) REFERENCES Member (memberId) ON DELETE CASCADE
    );

-- Note to grader: for this project to be fully feature complete, a trigger is needed to enforce 10 active rentals per member. Alternatively, this can be enforced at the application level (which is what I would do in a real-world scenario).