from classes.Contact import Contact
from classes.Event import Event

"""
This class represents a tuple of 1 Event and 1 Contact object, meaning the Contact is attending the Event.
This is its own class because there will be attributes associated to a contact attending an event, e.g.
whether they need a parking pass, special accommodations, etc. 

For now, the "memo" attribute is a catch-all for these, but in the future, more attributes will be added.
"""


class EventAttendee:
    def __init__(self, contact, event):
        self.__contact = contact
        self.__event = event
        self.__memo = ''

    # This function defines what happens when you print the object as text, i.e. print(event_attendee)
    # PRINTS IN THE FORM "John Smith attending Data Science League Meeting"
    def __str__(self):
        """
        python has a few ways of streamlining concatenation of strings.
        each time there's a {} in the string that represents a variable.
        notice at the end of the string, ".format()"
        the variables passed into this function will replace each {} (in order)
        """
        return "{} {}\nattending\n{}".format(self.__contact.firstname, self.__contact.lastname, self.__event.name)
    
    @property
    def contact(self):
        return self.__contact
    @contact.setter
    def contact(self, contact):
        self.__contact = contact
    @property
    def event(self):
        return self.__event
    @event.setter
    def event(self, event):
        self.__event = event
    @property
    def memo(self):
        return self.__memo
    @memo.setter
    def memo(self, memo):
        self.__memo = memo