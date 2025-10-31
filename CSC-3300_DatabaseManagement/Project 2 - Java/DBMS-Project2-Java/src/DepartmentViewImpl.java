import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.SQLException;

public class DepartmentViewImpl implements DepartmentView {

    public void retrieveDepartments(Connection conn) throws SQLException {
        DepartmentMgImpl departmentMg = new DepartmentMgImpl();
        departmentMg.retrieveDepartments(conn);
    }

    /**
     * Adds a department.
     * 
     * @param connection a connection with a specific database
     * @param dept_name  name of the department
     * @param building   value for the main location of the office of the department
     * @param budget     budget of the department
     * @return (1) 1 if the department was added or (2) 0 if the department was not
     *         added or (3) -1 if any of the values for department name, building,
     *         or budget are invalid
     * @throws SQLException if a database error occurs
     */
    public int addDepartment(Connection conn, String dept_name, String building, String budget)
            throws SQLException {
        BigDecimal budgetDecimal = null;
        try {
            budgetDecimal = new BigDecimal(budget);
        } catch (NumberFormatException e) {
            // throw new IllegalArgumentException("Budget must be a valid decimal number");
            return -1;
        }

        if (dept_name == null || dept_name.length() > 20) {
            // throw new IllegalArgumentException("Department name must be 20 characters or
            // less");
            return -1;
        }
        if (building == null || building.length() > 15) {
            // throw new IllegalArgumentException("Building name must be 15 characters or
            // less");
            return -1;
        }
        if (budgetDecimal == null || budgetDecimal.intValue() < 1 || budgetDecimal.intValue() > 10000000000L) {
            throw new IllegalArgumentException("Budget must be between 1 and 10000000000.00");
        }

        DepartmentMgImpl departmentMg = new DepartmentMgImpl();
        return departmentMg.addDepartment(conn, dept_name, building, budgetDecimal);
    }

    /**
     * Updates building of a department.
     * 
     * @param connection a connection with a specific database
     * @param dept_name  name of the department to be updated
     * @param building   new value for the main location of the office of the
     *                   department
     * @return (1) 1 if the building of the department was updated or (2) 0 if the
     *         building of the department was not updated or (3) -1 if the value for
     *         the building is invalid
     * @throws SQLException if a database error occurs
     */
    public int updateDepartmentBuilding(Connection conn, String dept_name, String building) throws SQLException {
        if (dept_name == null || dept_name.length() > 20) {
            // throw new IllegalArgumentException("Department name must be 20 characters or
            // less");
            return -1;
        }
        if (building == null || building.length() > 15) {
            // throw new IllegalArgumentException("Building name must be 15 characters or
            // less");
            return -1;
        }

        DepartmentMgImpl departmentMg = new DepartmentMgImpl();
        return departmentMg.updateDepartmentBuilding(conn, dept_name, building);
    }

    /**
     * Updates budget of a department.
     * 
     * @param connection a connection with a specific database
     * @param dept_name  name of the department to be updated
     * @param budget     new budget of the department
     * @return (1) 1 if the budget of the department was updated or (2) 0 if the
     *         budget of the department was not updated or (3) -1 if the value for
     *         the budget is invalid
     * @throws SQLException if a database error occurs
     */
    public int updateDepartmentBudget(Connection conn, String dept_name, String budget) throws SQLException {
        BigDecimal budgetDecimal = null;
        try {
            budgetDecimal = new BigDecimal(budget);
        } catch (NumberFormatException e) {
            // throw new IllegalArgumentException("Budget must be a valid decimal number");
            return -1;
        }

        if (dept_name == null || dept_name.length() > 20) {
            // throw new IllegalArgumentException("Department name must be 20 characters or
            // less");
            return -1;
        }
        if (budgetDecimal == null || budgetDecimal.intValue() < 1 || budgetDecimal.intValue() > 10000000000L) {
            // throw new IllegalArgumentException("Budget must be between 1 and
            // 10000000000.00");
            return -1;
        }

        DepartmentMgImpl departmentMg = new DepartmentMgImpl();
        return departmentMg.updateDepartmentBudget(conn, dept_name, budgetDecimal);
    }

    /**
     * Updates building and budget of a department.
     * 
     * @param connection a connection with a specific database
     * @param dept_name  name of the department to be updated
     * @param building   new value for the main location of the office of the
     *                   department
     * @param budget     new budget of the department
     * @return (1) 1 if the building and budget of the department were updated or
     *         (2) 0 if the building and budget of the department were not updated
     *         cause the department is not there or (3) -1 if the value for either
     *         building or budget is invalid
     * @throws SQLException if a database error occurs
     */
    public int updateDepartmentBuildingAndBudget(Connection conn, String dept_name, String building, String budget)
            throws SQLException {
        BigDecimal budgetDecimal = null;
        try {
            budgetDecimal = new BigDecimal(budget);
        } catch (NumberFormatException e) {
            // throw new IllegalArgumentException("Budget must be a valid decimal number");
            return -1;
        }

        if (dept_name == null || dept_name.length() > 20) {
            // throw new IllegalArgumentException("Department name must be 20 characters or
            // less");
            return -1;
        }
        if (building == null || building.length() > 15) {
            // throw new IllegalArgumentException("Building name must be 15 characters or
            // less");
            return -1;
        }
        if (budgetDecimal == null || budgetDecimal.intValue() < 1 || budgetDecimal.intValue() > 10000000000L) {
            // throw new IllegalArgumentException("Budget must be between 1 and
            // 10000000000.00");
            return -1;
        }

        DepartmentMgImpl departmentMg = new DepartmentMgImpl();
        return departmentMg.updateDepartmentBuildingAndBudget(conn, dept_name, building, budgetDecimal);
    }

    /**
     * Removes department from the university database.
     * 
     * @param connection a connection with a specific database
     * @param dept_name  name of the department to be removed
     * @return (1) 1 if the department was removed or (2) 0 if no department was
     *         removed
     * @throws SQLException if a database error occurs
     */
    public int removeDepartment(Connection conn, String dept_name) throws SQLException {
        if (dept_name == null || dept_name.length() > 20) {
            // throw new IllegalArgumentException("Department name must be 20 characters or
            // less");
            return -1;
        }

        DepartmentMgImpl departmentMg = new DepartmentMgImpl();
        return departmentMg.removeDepartment(conn, dept_name);
    }
}
