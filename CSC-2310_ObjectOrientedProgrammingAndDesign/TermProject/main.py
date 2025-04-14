from classes.EventManager import EventManager
from UI.gui import GUI
import json


# Press the green button in the gutter to run the project.
if __name__ == '__main__':

    with open('contacts.json') as contacts_json:
        contact_data = json.load(contacts_json)
    with open('events.json') as events_json:
        event_data = json.load(events_json)

    # initialize the EventManager object (there's only 1 instance of it)
    event_manager = EventManager()

    # load pre-existing contacts into event_manager (from 'contacts.json')
    for x in contact_data:
        event_manager.add_contact(x)

    # add all events from the events.json into the event manager
    for x in event_data["university_events"]:
        event_manager.add_event(x)

    # initialize the gui object (from tkinter) and pass the event_manager object into it
    gui = GUI(event_manager)
    gui.mainloop()
