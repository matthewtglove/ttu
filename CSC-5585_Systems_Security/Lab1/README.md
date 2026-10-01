## License & Usage

Copyright (c) 2026 Maraz Mia. All rights reserved.

This project is provided for distribution under the following strict conditions:
1. **No Modifications:** You may copy and redistribute this software exactly as it is. You are not permitted to alter, transform, or build upon this code.
2. **Non-Commercial:** You may not use, share, or redistribute this software for commercial purposes or financial gain. It cannot be sold.
3. **Attribution:** You must keep this copyright notice and permission statement intact in all copies.





## Setup and Installation on VS Code

Follow these steps to create your virtual environment, install the required dependencies, and prepare the project for execution on a Windows machine.

### 1. Create the Virtual Environment
Open your PowerShell in the project root directory (Web Application Security Lab) and run the following command to create a virtual environment named `env` (all labs are tested against Python 3.11.5, guessing that you have python installed already!!!):

```powershell
python -m venv .venv
```

### 2. Activate the Virtual Environment
Activate the environment using the appropriate command in case you wann run some python script

For windows:

```powershell
.venv\Scripts\Activate.ps1
```

For Linux:

```shell
source .venv/bin/activate
```


### 3. Install the required python libraries

```powershell
python -m pip install --upgrade pip
pip install -r requirements.txt
```

### 4. Running the python file for lab1_api_security

Navigate to the project folder then run it

```powershell
cd lab1_api_security/vulnerable_api/
python app.py
```

Keep the backend app.py file running all the time else your website won't show on the browser. You can ctl+right click from the terminal to open the website inside VSCode or can use a normal broswer by copy and paste the given website URL. Once you create the virtual environment and the python libraries, you don't have to do it later. So, in future, just activate the virtual environment before running any python script.

If in linux, for running the python3 command gives you error, try with plain python instead without the suffix "3".
