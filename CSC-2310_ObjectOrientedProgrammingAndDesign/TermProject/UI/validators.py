import re


def is_an_integer(user_input) -> bool:
    """
    Checks if given user input is numeric.
    :param user_input: User input to be validated.
    :return: (Bool) Input validity, true if valid.
    """
    return user_input == "" or user_input.isdigit()


def is_a_valid_email_address(user_input) -> bool:
    """
    Checks if given user input is a valid email address by the RFC 5322 standard.
    :param user_input: User input to be validated.
    :return: Validity of the input as an email address.
    """
    return user_input == "" or bool(re.match(r"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)", user_input))


def is_a_valid_phone_number(user_input) -> bool:
    """
    Checks if given user input is a valid phone number or `--`
    :param user_input: User input to be validated.
    :return: Validity of the input as a phone number.
    """
    return user_input == "" or bool(re.match(r"\(?\d{0,3}\)?-\d{0,3}-\d{0,4}", user_input))
