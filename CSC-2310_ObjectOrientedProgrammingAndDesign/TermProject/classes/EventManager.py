from classes.EventAttendee import EventAttendee
from classes.Event import Event
from classes.Contact import Contact

'''
This file is where the bulk of your work will be done. 
I have listed each category of method you will need to create in the comments.
I have also listed how many methods will appear in each category.
'''

class EventManager:
    """
    This class is meant to manage the Events, Contacts, and Event_Attendees.
    This class also directly communicates with the GUI as the GUI "has" an EventManager object (aggregation).
    This class has a list of Event objects, a list of Contact objects, and a list of EventAttendee objects.
    """
    # constructor (1 method)
    def __init__(self):
        self._events = []
        self._contacts = []
        self._event_attendees = []
        self._event_uids = 0
        self._contact_uids = 0

    # getters (5 methods) and setters (5 methods)
    @property
    def events(self):
        return self._events
    @events.setter
    def events(self, events):
        self._events = events
    @property
    def contacts(self):
        return self._contacts
    @contacts.setter
    def contacts(self, contacts):
        self._contacts = contacts
    @property
    def event_attendees(self):
        return self._event_attendees
    @event_attendees.setter
    def event_attendees(self, event_attendees):
        self._event_attendees = event_attendees
    @property
    def event_uids(self):
        return self._event_uids
    @event_uids.setter
    def event_uids(self, event_uids):
        self._event_uids = event_uids
    @property
    def contact_uids(self):
        return self._contact_uids
    @contact_uids.setter
    def contact_uids(self, contact_uids):
        self._contact_uids = contact_uids

    # other methods (6 methods)

    def add_event(self, event: dict):
        self._events.append(Event(event))
        self._event_uids += 1
        self._sort_events()

    def add_contact(self, contact: dict):
        self._contacts.append(Contact(contact))
        self._contact_uids += 1
        self._sort_contacts()

    def is_attending(self, contact, event) -> bool:
        for x in self._event_attendees:
            if (x.contact == contact and x.event == event):
                return True
        return False

    def add_event_attendee(self, contact, event):
        if (self.is_attending(contact, event)):
            return
        self._event_attendees.append(EventAttendee(contact, event))

    def uid_to_event(self, uid):
        for x in self._events:
            if (x.uid == uid):
                return x
        return None

    def uid_to_contact(self, uid):
        for x in self._contacts:
            if (x.uid == uid):
                return x
        return None

    # pre-existing methods (2 methods; they are already here; no need to touch them)

    def _sort_contacts(self) -> None:
        """
        Sort contacts by their last name
        :returns: None
        """
        # sort the list by lastname (alphabetically)
        self._contacts.sort(key=lambda x: x.lastname)

    def _sort_events(self) -> None:
        """
        Sort the stored events by date
        :returns: None
        """
        self._events.sort(key=lambda x: x.date, reverse=False)
