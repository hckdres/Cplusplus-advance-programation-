import java.io.BufferedReader;
import java.io.InputStreamReader;

class Nomina2 {
    public static void main(String[] args) throws Exception {
        int numeroEmpleados;
        Empleado[] losEmpleados = new Empleado[50];
        String cedula, apellido, nombre;
        double horas, sueldo;
        double total = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Digite el número de empleados: ");
        numeroEmpleados = Integer.parseInt(br.readLine());

        for (int i = 0; i < numeroEmpleados; i++) {
            System.out.println("\nEmpleado #" + (i + 1));

            System.out.print("Digite la cédula del empleado: ");
            cedula = br.readLine();

            System.out.print("Digite el apellido del empleado: ");
            apellido = br.readLine();

            System.out.print("Digite el nombre del empleado: ");
            nombre = br.readLine();

            System.out.print("Digite el número de horas trabajadas: ");
            horas = Double.parseDouble(br.readLine());

            System.out.print("Digite el sueldo por hora: ");
            sueldo = Double.parseDouble(br.readLine());

            Empleado unEmpleado = new Empleado(cedula, apellido, nombre, horas, sueldo);
            losEmpleados[i] = unEmpleado;
        }

        // Calcular el total de la nómina
        for (int i = 0; i < numeroEmpleados; i++) {
            total += losEmpleados[i].calcularSalario();
        }

        System.out.println("\nEl total de la nómina es: " + total);
    }
}