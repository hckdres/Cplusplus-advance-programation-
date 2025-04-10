import java.io.BufferedReader;
import java.io.InputStreamReader;

class Nomina {

  public static void main(String[] args)throws Exception{

    int numEmpleados;
    String[] cedulas = new String[50];
    String[] apellidos = new String[50];
    String[] nombres = new String[50];
    double[] horasTrabajadas = new double[50];
    double[] sueldoPorHora = new double[50];
    String cedula, apellido, nombre;
    double horas, sueldo;
    double total = 0;

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    System.out.println("Ingrese el numero de empleados: ");
    numEmpleados = Integer.valueOf(br.readLine()).intValue();

    for (int i = 0; i < numEmpleados; i++){

      System.out.println("Ingrese la cedula del empleado: ");
      cedula = br.readLine();

      System.out.println("Ingrese el apellido del empleado: ");
      apellido = br.readLine();

      System.out.println("Ingrese el nombre del empleado: ");
      nombre = br.readLine();

      System.out.println("Ingrese las horas trabajadas del empleado: ");
      horas = Double.valueOf(br.readLine()).doubleValue();

      System.out.println("Ingrese el sueldo por hora del empleado: ");
      sueldo = Double.valueOf(br.readLine()).doubleValue();

      cedulas[i] = cedula;
      apellidos[i] = apellido;
      nombres[i] = nombre;
      horasTrabajadas[i] = horas;
      sueldoPorHora[i] = sueldo;
      }
    for (int i = 0; i < numEmpleados; i++){

      total = total + horasTrabajadas[i] * sueldoPorHora[i];
    }
    System.out.println("La nomina total es: " + total);
  }

}