import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.SQLIntegrityConstraintViolationException;

public class Manager {

	public static void main(String[] args) {
		try {
			/**
			 * Returns the Class object associated with the class or interface with the
			 * given string name. Given the fully qualified name for a class or interface
			 * this method attempts to locate, load, and link the class or interface.
			 * https://docs.oracle.com/javase/8/docs/api/java/lang/Class.html
			 */
			Class.forName("com.mysql.cj.jdbc.Driver");

			java.util.Scanner scan = new java.util.Scanner(System.in);
			System.out.println("Username: ");
			String username = scan.nextLine();
			System.out.println("Password: ");
			String password = scan.nextLine();

			DepartmentView dvi = new DepartmentViewImpl();

			try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/university", username,
					password)) {

				int choice;


				while (true) {

					while (true) {
						print_options();
						try {
							choice = Integer.parseInt(scan.next());
							break;
						} catch (NumberFormatException not_num) {
							System.out.println("Not a valid value");
						}
					}

					String dept_name;
					String building;
					String budget;

					switch (choice) {
					case 1:
						dvi.retrieveDepartments(conn);
						break;
					case 2:
						scan.nextLine();

						System.out.println("Department name: ");
						dept_name = scan.nextLine();

						System.out.println("Building: ");
						building = scan.nextLine();

						System.out.println("Budget: ");
						budget = scan.nextLine();

						try {
							dvi.addDepartment(conn, dept_name, building, budget);
						} catch (SQLIntegrityConstraintViolationException e) {
							System.out.println("There is already a department with a given name.");
						}

						break;

					case 3:
						scan.nextLine();

						System.out.println("Department name: ");
						dept_name = scan.nextLine();

						System.out.println("Building: ");
						building = scan.nextLine();

						dvi.updateDepartmentBuilding(conn, dept_name, building);
						break;

					case 4:
						scan.nextLine();

						System.out.println("Department name: ");
						dept_name = scan.nextLine();

						System.out.println("Budget: ");
						budget = scan.nextLine();

						dvi.updateDepartmentBudget(conn, dept_name, budget);
						break;

					case 5:
						scan.nextLine();

						System.out.println("Department name: ");
						dept_name = scan.nextLine();

						System.out.println("Building: ");
						building = scan.nextLine();

						System.out.println("Budget: ");
						budget = scan.nextLine();

						dvi.updateDepartmentBuildingAndBudget(conn, dept_name, building, budget);
						break;

					case 6:
						scan.nextLine();

						System.out.println("Department name: ");
						dept_name = scan.nextLine();

						dvi.removeDepartment(conn, dept_name);
						break;
					case 7:
						scan.close();
						try {
							conn.close();
							System.out.println("Database Connection Terminated, GoodBye!");
						} catch (SQLException operation_failed) {
							System.out.println("Unable to properly disconnect from server");
						}
						return;
					default:
						System.out.println("Invalid input, try again");
					}
				}

			} catch (SQLException e) {
				e.printStackTrace();
			}
			scan.close();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}

	public static void print_options() {
		System.out.println("");
		System.out.println("Choose from the following menu");
		System.out.println("1. Retrieve info about all departments");
		System.out.println("2. Add department");
		System.out.println("3. Change department's building");
		System.out.println("4. Change department's budget");
		System.out.println("5. Change department's building and budget");
		System.out.println("6. Remove department");
		System.out.println("7. Quit");
		System.out.println("");
	}
}