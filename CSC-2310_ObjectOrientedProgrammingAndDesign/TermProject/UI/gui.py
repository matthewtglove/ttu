from classes.Contact import Contact
from classes.Event import Event
from classes.EventAttendee import EventAttendee
from classes.EventManager import EventManager
from classes.SearchContacts import SearchContacts
from tkinter import (Tk, LabelFrame, Button, Label, Entry, Variable, Listbox, END, Text, Event as TKEvent, TOP, BOTTOM,
                     LEFT, BOTH, Frame, RIGHT, messagebox)
from typing import List, Union, TYPE_CHECKING
from UI.validators import *


class GUI(Tk):
    def __init__(self, event_manager: EventManager, debug: bool = False, *args, **kwargs):
        self.__debug: bool = debug
        # Setup for the tkinter window
        super().__init__(*args, **kwargs)
        self.fontsize: int = 18
        self.font: str = 'Arial'
        # This sets the text in the window border
        self.title("OOP TERM PROJECT")
        # This line sets the resolution
        self.geometry("640x480")
        # This is part of the closing function (whenever you ex out of the program)
        self.protocol("WM_DELETE_WINDOW", self.destroy)
        # Make the window resizable
        self.resizable(True, True)

        # Make PyCharm happy when it comes to declaration and typing
        if TYPE_CHECKING:
            self.side_buttons: Union[LabelFrame, None] = None
            self.button_add_contact: Union[Button, None] = None
            self.button_add_event: Union[Button, None] = None
            self.button_display_contacts: Union[Button, None] = None
            self.button_display_events: Union[Button, None] = None
            self.label_firstname: Union[Label, None] = None
            self.firstname_entry: Union[Entry, None] = None
            self.label_lastname: Union[Label, None] = None
            self.lastname_entry: Union[Entry, None] = None
            self.label_email: Union[Label, None] = None
            self.email_entry: Union[Entry, None] = None
            self.label_department: Union[Label, None] = None
            self.department_entry: Union[Entry, None] = None
            self.label_title: Union[Label, None] = None
            self.title_entry: Union[Entry, None] = None
            self.label_phone: Union[Label, None] = None
            self.phone_entry: Union[Entry, None] = None
            self.label_building: Union[Label, None] = None
            self.building_entry: Union[Entry, None] = None
            self.button: Union[Button, None] = None
            self.label_contact: Union[Label, None] = None
            self.button_add_another_contact: Union[Button, None] = None
            self.label_event_name: Union[Label, None] = None
            self.event_name_entry: Union[Entry, None] = None
            self.label_event_date: Union[Label, None] = None
            self.event_date_entry: Union[Entry, None] = None
            self.label_event_start_time: Union[Label, None] = None
            self.event_start_time_entry: Union[Entry, None] = None
            self.label_event_location: Union[Label, None] = None
            self.event_location_entry: Union[Entry, None] = None
            self.label_event_duration: Union[Label, None] = None
            self.event_duration_entry: Union[Entry, None] = None
            self.label_event: Union[Label, None] = None
            self.button_add_another_event: Union[Button, None] = None
            self.listbox: Union[Listbox, None] = None
            self.button_back: Union[Button, None] = None
            self.label_contact_single: Union[Label, None] = None
            self.label_last_contact: Union[Label, None] = None
            self.last_contact_entry: Union[Entry, None] = None
            self.last_contact_button: Union[Label, None] = None
            self.listbox_events: Union[Listbox, None] = None
            self.label_event_single: Union[Label, None] = None
            self.button_list_attendees_going: Union[Button, None] = None
            self.button_list_contacts: Union[Button, None] = None
            self.list_box_attendees_going: Union[Listbox, None] = None
            self.label_event_attendee: Union[Label, None] = None
            self.label_memo: Union[Label, None] = None
            self.memo_text: Union[Text, None] = None
            self.button_memo: Union[Label, None] = None
            self.listbox_contacts: Union[Listbox, None] = None
            self.search_entry: Union[Entry, None] = None
            self.contact_list: list = []

        # Grab the event manager
        self.event_manager = event_manager

        # Grab the Contact Search
        self.contact_search = SearchContacts()

        # This variable is used to create an EventAttendee object later on
        self.current_event: int = 0
        self.current_event_uid: int = -1
        self.uid_list = []

        # These are used to destroy the dropdown lists on the same page
        self.is_current_attendees_dropdown: bool = False
        self.is_add_attendees_dropdown: bool = False

        # Create the navigation sidebar of the application
        self.create_side_bar()

    def clear_frame(self) -> None:
        """
        This clears the right-hand frame of all widgets. This is called every time the menu changes to another screen
        :return: None
        """
        for widgets in self.frame.winfo_children():
            widgets.destroy()

    def button_state(self, button: str) -> None:
        """
        this function disables the button you have clicked (mainly to mark which page you are currently on) a string
        is passed in to check which button has been pressed
        :param button: The button to disable
        :return: None
        """
        # the buttons have 2 states: "normal" and "disabled"
        # "disabled" will gray it out and make you unable to click it

        # this enables all buttons
        self.button_add_contact["state"] = "normal"
        self.button_add_event["state"] = "normal"
        self.button_display_contacts["state"] = "normal"
        self.button_display_events["state"] = "normal"

        # this will then check and disable whichever button was pressed
        if button == "add_contact":
            self.button_add_contact["state"] = "disabled"

        elif button == "add_event":
            self.button_add_event["state"] = "disabled"

        elif button == "display_contacts":
            self.button_display_contacts["state"] = "disabled"

        elif button == "display_events":
            self.button_display_events["state"] = "disabled"

    def create_side_bar(self) -> None:
        """
        Create the sidebar (the frame on the left of the screen with the buttons: "Create Contact", "Create Event",
        "Display Contacts", "Display Events")
        :return: None
        """
        # create the frame for the side buttons "Create Contact", "Create Event", etc. (this will always be on the
        # screen)
        self.side_buttons = LabelFrame(self, padx=2, pady=10)
        # this pack() function is what places the frame on the screen
        self.side_buttons.pack(side="left", expand=False, fill="both")

        # add_contact button
        # Every widget (buttons, text inputs, labels etc.) is defined first, then placed on the screen using pack()

        # The first argument is which frame to place the button in which in this case is self.side_buttons which was
        # defined above "command=" is saying that whenever the button is clicked on, the self.contact_screen function
        # will be called NOTE: that self.contact_screen does not have "()" at the end. We don't want to call the
        # function at this time, only link it to the button.
        self.button_add_contact = Button(self.side_buttons, text="Create Contact", font=(self.font, self.fontsize),
                                         command=self.contact_screen)
        # We defined the button above, now using pack() we will place it in the next available spot in the frame
        # "side_buttons". In future implementations, pack() may be replaced by grid() as you can specify which row and
        # column to place the button. pack() was used to save time for now
        self.button_add_contact.pack(expand=True, fill=BOTH)

        # add_event button
        self.button_add_event = Button(self.side_buttons, text="Create Event", font=(self.font, self.fontsize),
                                       command=self.event_screen)
        self.button_add_event.pack(expand=True, fill=BOTH)

        # display contacts button
        self.button_display_contacts = Button(self.side_buttons, text="Display Contacts",
                                              font=(self.font, self.fontsize), command=self.display_contacts)
        self.button_display_contacts.pack(expand=True, fill=BOTH)

        # display events button
        self.button_display_events = Button(self.side_buttons, text="Display Events", font=(self.font, self.fontsize),
                                            command=self.display_events)
        self.button_display_events.pack(expand=True, fill=BOTH)

        # establish the frame that will house each type of form. this will be cleared, then repopulated will the
        # selected form or "state"
        # NOTE: This frame will house everything on the screen that isn't on the sidebar on the left
        self.frame = LabelFrame(self, padx=0, pady=10)
        self.frame.pack(side="right", expand=True, fill="both")

    def contact_screen(self) -> None:
        """
        Creates the contact creation screen whenever the "Create Contact" button is pressed
        :return: None
        """
        # before creating the screen, we need to clear whatever is there in the frame
        self.clear_frame()

        # this will disable the "add_contact" button on the screen since we have just clicked on it
        self.button_state("add_contact")

        # these are label definitions followed by text entry box definitions for each attribute
        # this label will simply say 'First Name' above the text box
        self.label_firstname = Label(self.frame, text="First Name", font=(self.font, self.fontsize))
        # this text box is for entering the first name
        self.firstname_entry = Entry(self.frame)
        self.label_lastname = Label(self.frame, text="Last Name", font=(self.font, self.fontsize))
        self.lastname_entry = Entry(self.frame)
        self.label_email = Label(self.frame, text="Email", font=(self.font, self.fontsize))
        self.email_entry = Entry(self.frame)
        self.label_department = Label(self.frame, text="Department", font=(self.font, self.fontsize))
        self.department_entry = Entry(self.frame)
        self.label_title = Label(self.frame, text="Title", font=(self.font, self.fontsize))
        self.title_entry = Entry(self.frame)
        self.label_phone = Label(self.frame, text="Phone #", font=(self.font, self.fontsize))
        self.phone_entry = Entry(self.frame)
        self.label_building = Label(self.frame, text="Building", font=(self.font, self.fontsize))
        self.building_entry = Entry(self.frame)

        email_callback = self.frame.register(is_a_valid_email_address)
        invalid_email_callback = self.frame.register(lambda x: self.invalid_input("email"))
        self.email_entry.config(validate="focusout", validatecommand=(email_callback, '%P'),
                                invalidcommand=(invalid_email_callback, "%P"))

        phone_callback = self.frame.register(is_a_valid_phone_number)
        invalid_phone_callback = self.frame.register(lambda x: self.invalid_input("phone number"))
        self.phone_entry.config(validate="focusout", validatecommand=(phone_callback, '%P'),
                                invalidcommand=(invalid_phone_callback, "%P"))

        """ 
        The pack() function will put the Gui component in the next available space on the screen. It's a quick fix. 
        Other methods are available that look better, but this works for now.
        """
        self.label_firstname.pack()
        self.firstname_entry.pack()
        self.label_lastname.pack()
        self.lastname_entry.pack()
        self.label_email.pack()
        self.email_entry.pack()
        self.label_department.pack()
        self.department_entry.pack()
        self.label_title.pack()
        self.title_entry.pack()
        self.label_phone.pack()
        self.phone_entry.pack()
        self.label_building.pack()
        self.building_entry.pack()

        # pressing this button in the Gui will create a new contact with the entered info from the above text boxes
        self.button = Button(self.frame, text="Create", font=(self.font, self.fontsize),
                             command=self.form_submission_contact)
        self.button.pack()

    def form_submission_contact(self):
        """
        We are collecting the input from each text field and creating a dictionary.
        This is then passed into the event managers add_contact method which
        passed the same dictionary into the constructor of the Contact class
        """
        a = {
            "FirstName": self.firstname_entry.get(),
            "LastName": self.lastname_entry.get(),
            "UID": self.event_manager._contact_uids,
            "EmailAddress": self.email_entry.get(),
            "Dept": self.department_entry.get(),
            "Title": self.title_entry.get(),
            "Phone": self.phone_entry.get(),
            "Building": self.building_entry.get()
        }

        # add a new contact to the event manager's list of contacts using the dictionary data
        self.event_manager.add_contact(a)

        # clear the frame and print on the screen "Contact Added!"
        self.clear_frame()
        self.label_contact = Label(self.frame, text="Contact Added!\n", font=('Arial', 18))
        self.label_contact.pack()

        # prompt user to add another contact if they want
        self.button_add_another_contact = Button(self.frame, text="Create Another?", font=(self.font, self.fontsize),
                                                 command=self.contact_screen)
        self.button_add_another_contact.pack()

    def event_screen(self) -> None:
        """
        Creates the "Create Event" screen when clicking the button
        :return: None
        """
        self.clear_frame()

        self.button_state("add_event")
        # these are label definitions followed by text entry box definitions for each attribute
        # this label will simply say 'First Name' above the text box
        self.label_event_name = Label(self.frame, text="Event Name", font=(self.font, self.fontsize))
        # this text box is for entering the first name
        self.event_name_entry = Entry(self.frame)

        self.label_event_date = Label(self.frame, text="Date (yyyy-mm-dd)", font=(self.font, self.fontsize))
        self.event_date_entry = Entry(self.frame)

        self.label_event_start_time = Label(self.frame, text="Start Time", font=(self.font, self.fontsize))
        self.event_start_time_entry = Entry(self.frame)

        self.label_event_location = Label(self.frame, text="Location", font=(self.font, self.fontsize))
        self.event_location_entry = Entry(self.frame)

        self.label_event_duration = Label(self.frame, text="Duration (hours)", font=(self.font, self.fontsize))
        self.event_duration_entry = Entry(self.frame)
        event_callback = self.frame.register(is_an_integer)
        self.event_duration_entry.config(validate="key", validatecommand=(event_callback, '%P'))

        """ 
        The pack() function will put the Gui component in the next available space on the screen. It's a quick fix. 
        Other methods are available that look better, but this works for now.
        """
        self.label_event_name.pack()
        self.event_name_entry.pack()

        self.label_event_date.pack()
        self.event_date_entry.pack()
        self.label_event_start_time.pack()
        self.event_start_time_entry.pack()
        self.label_event_location.pack()
        self.event_location_entry.pack()
        self.label_event_duration.pack()
        self.event_duration_entry.pack()

        # pressing this button in the Gui will create a new contact with the entered info from the above text boxes
        self.button = Button(self.frame, text="Create", font=(self.font, self.fontsize),
                             command=self.form_submission_event)
        self.button.pack()

    def form_submission_event(self) -> None:
        """
        This function is called when you click the "Create" button on the "Create Event" screen (adding a new event to
        the event manager's list)
        :return: None
        """
        # a dictionary is created with event info then used to create an event
        a = {
            "Name": self.event_name_entry.get(),
            "Date": self.event_date_entry.get(),
            "UID": self.event_manager._event_uids,
            "StartTime": self.event_start_time_entry.get(),
            "Location": self.event_location_entry.get(),
            "Duration": int(self.event_duration_entry.get())
        }

        self.event_manager.add_event(a)

        self.clear_frame()
        self.label_event = Label(self.frame, text="Event Added!\n", font=('Arial', 18))
        self.label_event.pack()

        self.button_add_another_event = Button(self.frame, text="Create Another?", font=(self.font, self.fontsize),
                                               command=self.event_screen)
        self.button_add_another_event.pack()

    def display_contacts(self, query: Union[str, None] = None) -> None:
        """
        Display all the contacts in a list when clicking the "Display Contacts" button
        :return: None
        """
        self.clear_frame()
        self.button_state("display_contacts")
        button_frame = Frame(self.frame)

        # Search Bar
        self.search_entry = Entry(self.frame, width=30, font=(self.font, self.fontsize))
        self.search_entry.pack(pady=5, side=TOP, expand=True, fill=BOTH)

        search_button = Button(button_frame, text="Search",
                               command=lambda: self.display_contacts(self.search_entry.get()))
        search_button.pack(side=LEFT, expand=True)

        reset_button = Button(button_frame, text="Reset", command=self.display_contacts)
        reset_button.pack(side=RIGHT, expand=True)
        button_frame.pack(expand=True, pady=5)

        self.contact_list = []
        # get a list of contacts' first and last names
        if not query:
            for x in self.event_manager._contacts:
                self.contact_list.append(f"{x.lastname}, {x.firstname}")
        else:
            for x in self.contact_search.search(query, self.event_manager._contacts):
                self.contact_list.append(f"{x.lastname}, {x.firstname}")
        list_items = Variable(value=self.contact_list)
        self.listbox = Listbox(self.frame, width=25, height=len(self.contact_list), font=(self.font, self.fontsize),
                               listvariable=list_items)
        self.listbox.bind('<<ListboxSelect>>', self.select_contact)
        self.listbox.pack(side=BOTTOM)

    def select_contact(self, event: TKEvent) -> None:
        """
        When a contact is selected from the list to see their info on the "Display Contacts" screen.
        :return: None
        """
        if self.__debug:
            print(event)
        # get all selected indices
        selected_index = self.listbox.curselection()
        self.display_contact_single(int(selected_index[0]))

    def display_contact_single(self, selected_index) -> None:
        """
        This will display a single contact's info once clicked from the dropdown menu on "Display Contacts" screen
        :param selected_index:
        :return: None
        """
        self.clear_frame()
        # add a back button
        self.button_back = Button(self.frame, text="< Back", font=(self.font, 10), command=self.display_contacts)
        self.button_back.pack()

        contact_str = self.contact_list[selected_index]
        contact = None
        for contact_object in self.event_manager._contacts:
            if f"{contact_object.lastname}, {contact_object.firstname}" == contact_str:
                contact = contact_object
        if not contact:
            contact = self.event_manager._contacts[0]

        # contact = self.event_manager.contacts[selected_index]
        self.label_contact_single = Label(self.frame, text=contact, font=(self.font, self.fontsize), pady=10)
        self.label_contact_single.pack()

        # last point of contact
        self.label_last_contact = Label(self.frame, text="\nLast Point of Contact", font=(self.font, self.fontsize))
        self.label_last_contact.pack()

        self.last_contact_entry = Entry(self.frame)
        self.last_contact_entry.pack()
        # set the last point of contact entry box to the contacts attribute "last_contact"
        self.last_contact_entry.insert(END, contact.last_contact)
        # This button will save the last_contact_entry's text to the contacts "last_contact" attribute
        self.last_contact_button = Button(self.frame, text="Update Last Point of Contact", font=(self.font, 10),
                                          command=lambda: self.set_last_contact(contact))
        self.last_contact_button.pack()

    def set_last_contact(self, contact: Contact) -> None:
        """
        Set the last_contact attribute for a Contact object whenever you click "Update Last Point of Contact"
        :param contact: Contact object
        :return: None
        """
        contact.last_contact = self.last_contact_entry.get()

    def display_events(self) -> None:
        """
        Display all the events in a list when clicking the "Display Events" screen
        :return: None
        """
        self.clear_frame()
        self.button_state("display_events")
        event_list = []
        # get a list of contacts in the form of first and last names
        for x in self.event_manager._events:
            event_list.append(f"{x.date}: {x.name}")
        list_items = Variable(value=event_list)
        self.listbox_events = Listbox(self.frame, width=50, height=len(event_list), font=(self.font, self.fontsize),
                                      listvariable=list_items)
        self.listbox_events.bind('<<ListboxSelect>>', self.items_selected_event)
        self.listbox_events.pack()

    def items_selected_event(self, event: TKEvent) -> None:
        """
        This is called whenever you select an event from the selection list on the "Display Events" screen
        :return: None
        """
        if self.__debug:
            print(event)
        # get all selected indices
        selected_indices = self.listbox_events.curselection()
        self.display_event_single(int(selected_indices[0]))

    def display_event_single(self, selected_index: int) -> None:
        """
        This displays a single event using the event's print function. This is whenever you click on it in the
        selection list on "Display Events" screen
        :param selected_index: ID of the selected event
        :return: None
        """
        self.clear_frame()
        self.button_back = Button(self.frame, text="< Back", font=(self.font, 10), command=self.display_events)
        self.button_back.pack()
        self.current_event = selected_index
        event = self.event_manager._events[selected_index]

        self.label_event_single = Label(self.frame, text=event, font=(self.font, self.fontsize))
        self.label_event_single.pack()

        # This button will show current attendees for a given event
        self.button_list_attendees_going = Button(self.frame, text="Current Attendees", font=(self.font, self.fontsize),
                                                  command=self.list_attendees_going)
        self.button_list_attendees_going.pack()

        # disables the "Current Attendees" button if there are no attendees for the event, else enable it
        if self.attendee_count_for_event(self.current_event) == 0:
            self.button_list_attendees_going["state"] = "disabled"
        else:
            self.button_list_attendees_going["state"] = "normal"

        # add attendee button
        self.button_list_contacts = Button(self.frame, text="Add Attendee", font=(self.font, self.fontsize),
                                           command=self.add_attendees_list)
        self.button_list_contacts.pack()

    def attendee_count_for_event(self, event: int) -> int:
        """
        Counts the number of attendees for a given event (index in the event_manager's event list)
        :param event: Event id
        :return: (int) number of attendees
        """
        count = 0
        # iterate through the `event_attendees` list and check if its event is equal to the event (index in the event
        # list) passed as an argument
        for event_attendee in self.event_manager._event_attendees:
            if event_attendee.event == self.event_manager._events[event]:
                count += 1
        return count

    def list_attendees_going(self) -> None:
        """
        Lists the attendees (contacts) going to a particular event whenever you click the "Current Attendees" button
        :return: None
        """
        attendee_list: List[str] = []
        self.uid_list = []
        # check who all is going to the event, i.e., event_attendees in the list
        for x in self.event_manager._event_attendees:
            if x.event == self.event_manager._events[self.current_event]:
                attendee_list.append(f"{x.contact.lastname}, {x.contact.firstname}")
                self.uid_list.append(x.contact.uid)

        list_items = Variable(value=attendee_list)

        self.list_box_attendees_going = Listbox(self.frame, width=30, height=len(attendee_list),
                                                listvariable=list_items)
        self.list_box_attendees_going.pack()
        self.list_box_attendees_going.bind('<<ListboxSelect>>', self.display_event_attendee_single)
        # set the state of the buttons
        self.button_list_attendees_going["state"] = "disabled"
        self.button_list_contacts["state"] = "normal"

        self.is_current_attendees_dropdown = True
        # This will delete the add_attendees dropdown list that would otherwise be in the way
        if self.is_add_attendees_dropdown:
            self.listbox_contacts.destroy()
            self.is_add_attendees_dropdown = False

    def display_event_attendee_single(self, *args) -> None:
        """
        Display a single event_attendee object whenever you click on one in the dropdown list on "Display Events" screen
        :param args: selected event indices.
        :return: None
        """
        if self.__debug:
            print(args[0])
        selected_indices = self.list_box_attendees_going.curselection()
        self.clear_frame()

        # the back button goes back to the display_event_single screen
        self.button_back = Button(self.frame, text="< Back", font=(self.font, 10),
                                  command=lambda: self.display_event_single(self.current_event))
        self.button_back.pack()

        event: Event = self.event_manager._events[self.current_event]
        event_attendee = None

        contact: Contact = self.event_manager.uid_to_contact(self.uid_list[selected_indices[0]])

        # find the event_attendee object correlating with current event and current attendee (contact) selected
        for x in self.event_manager._event_attendees:
            if x.event == event and x.contact.uid == contact.uid:
                event_attendee = x
                break

        self.label_event_attendee = Label(self.frame, text=event_attendee, font=(self.font, self.fontsize))
        self.label_event_attendee.pack()
        # memo textbox
        self.label_memo = Label(self.frame, text="\nMemo:", font=(self.font, self.fontsize))
        self.label_memo.pack()
        self.memo_text = Text(self.frame, height=5, font=(self.font, self.fontsize))
        self.memo_text.pack()
        # insert event_attendee's memo into the textbox
        self.memo_text.insert(END, event_attendee.memo)
        self.button_memo = Button(self.frame, text="Save Memo", font=(self.font, self.fontsize),
                                  command=lambda: self.set_memo(event_attendee))
        self.button_memo.pack()

    def set_memo(self, event_attendee: EventAttendee) -> None:
        """
        Sets the memo for an event_attendee object. Called whenever you click "Save Memo".
        :param event_attendee: Event attendee to set the memo of.
        :return: None
        """
        event_attendee.memo = self.memo_text.get("1.0", 'end-1c')

    def add_attendees_list(self) -> None:
        """
        This makes a dropdown selection list of all the contacts (to add to an event) when you click "Add Attendee"
        :return: None
        """
        attendee_list: List[str] = []
        self.uid_list = []
        # list all the contacts in the event manager's contact list
        for x in self.event_manager._contacts:
            if not self.event_manager.is_attending(x, self.event_manager._events[self.current_event]):
                attendee_list.append(f"{x.lastname}, {x.firstname}")
                self.uid_list.append(x.uid)
        # take the list of contacts and assign it to the listbox variable
        list_items = Variable(value=attendee_list)
        # define listbox
        self.listbox_contacts = Listbox(self.frame, width=30, height=len(attendee_list), listvariable=list_items)
        # define the list box's function (when selecting an item)
        self.listbox_contacts.bind('<<ListboxSelect>>', self.add_attendees_selected)
        self.listbox_contacts.pack()
        # disable "Add Attendee" button
        self.button_list_contacts["state"] = "disabled"

        # disable the "Current Attendees" button if there are no attendees for the event, else enable it
        if self.attendee_count_for_event(self.current_event) == 0:
            self.button_list_attendees_going["state"] = "disabled"
        else:
            self.button_list_attendees_going["state"] = "normal"

        self.is_add_attendees_dropdown = True
        if self.is_current_attendees_dropdown:
            self.list_box_attendees_going.destroy()
            self.is_current_attendees_dropdown = False

    def add_attendees_selected(self, event: TKEvent) -> None:
        """
        Adds an attendee when a contact is selected in the event dropdown.
        :return: None
        """
        if self.__debug:
            print(event)
        self.button_list_contacts["state"] = "normal"

        # get all selected indices
        selected_indices = self.listbox_contacts.curselection()

        # Here we pass the selected index into the uid list and into the em's uid_to_contact function.
        # This returns a contact object
        contact: Contact = self.event_manager.uid_to_contact(self.uid_list[selected_indices[0]])
        # add new event_attendee to event_manager's list
        self.event_manager.add_event_attendee(contact, self.event_manager._events[self.current_event])

        # disable the "Current Attendees" button if there are no attendees for the event, else enable it
        if self.attendee_count_for_event(self.current_event) == 0:
            self.button_list_attendees_going["state"] = "disabled"
        else:
            self.button_list_attendees_going["state"] = "normal"

        self.listbox_contacts.destroy()

    def invalid_input(self, what: str) -> None:
        """
        Makes an error message.
        :param what: What the error is for.
        :return: None
        """
        messagebox.showerror(f"Invalid {what}", f"Please enter a valid {what}.")
