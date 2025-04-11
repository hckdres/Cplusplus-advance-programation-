public class Empleado {
    private String cedula;
    private String apellido;
    private String nombre;
    private double horasTrabajadas;
    private double sueldoXHora;

 public Empleado (String cedula, String apellido, String nombre, double horasTrabajadas, double sueldoXHora){
    this.cedula = cedula;
    this.apellido = apellido;
    this.nombre = nombre;
    this.horasTrabajadas = horasTrabajadas;
  }

  public double calcularsalario() {
    return horasTrabajadas * sueldoXHora;
  }

  public String getCedula() {
    return cedula;
  }

  public void setCedula(String cedula) {
    this.cedula = cedula;
  }

  public String getApellido() {
    return apellido;
  }

  public void setApellido(String apellido) {
    this.apellido = apellido;
  }

  public String getNombre() {
    return nombre;
  }

  public void setNombre(String nombre) {
    this.nombre = nombre;
  }

  public double getHorasTrabajadas() {
    return horasTrabajadas;
  }

  public void setHorasTrabajadas(double horasTrabajadas) {
    this.horasTrabajadas = horasTrabajadas;
  }

  public double getSueldoXHora() {
    return sueldoXHora;
  }

  public void setSueldoXHora(double sueldoXHora) {
    this.sueldoXHora = sueldoXHora;
  }
}
