import java.io.BufferedReader;
import java.io.InputStreamReader;

class Nomina1 {
    public static void main(String[] args) throws Exception{
      int numeroEmpleados;
      Empleado [] losEmpleados=new Empleado[50];
      String cedula,apellido,nombre;
      double horas,sueldo;
      double total=0;
      //creando un onjeto, le estoy pasando como argumento su constructor
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

      System.out.println("Digite el numero de empleados");
      numeroEmpleados=Integer.valueOf(br.readLine()).intValue();

      for(int i=0;i<numeroEmpleados;i++){
        System.out.println("Digite la cedula del empleado");
        cedula = br.readLine();
        System.out.println("Digite el apellido del empleado");
        apellido = br.readLine();
        System.out.println("Digite el nombre del empleado");
        nombre = br.readLine();
        System.out.println("Digite numero de horas trabajadas del empleado");
        horas = Double.valueOf(br.readLine()).doubleValue();
        System.out.println("Digite el sueldo X hora del empleado");
        sueldo = Double.valueOf(br.readLine()).doubleValue();

        Empleado unEmpleado=new Empleado();
        unEmpleado.cedula=cedula;
        unEmpleado.apellido=apellido;
        unEmpleado.nombre=nombre;
        unEmpleado.horasTrabajadas=horas;
        unEmpleado.sueldoXHora=sueldo;

        losEmpleados[i]=unEmpleado;
      }
      for(int i=0;i<numeroEmpleados;i++){
        total=total+losEmpleados[i].horasTrabajadas*losEmpleados[i].sueldoXHora;
      }
      System.out.println("El total de la nomina es: "+total);
    }
}