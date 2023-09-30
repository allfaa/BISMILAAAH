
import java.io.*;
class bank {
    public String[] nomer = new String [100];
    public String[] nama = new String [100];
    public String[] tabungan = new String [100];
    public String[] saldo = new String [100];
    private static int indek;
    private int jumlah_saldo;

    public String getNomer(int indek){
        return nomer[indek];
    }
    public String getNama(int indek){
        return nama[indek];
    }
    public String getTabungan(int indek){
        return tabungan[indek];
    }
    public String getSaldo(int indek){
        return saldo[indek];
    }
    public int getJumlah_saldo(){
        return jumlah_saldo++;
    }
    public void setJumlah_saldo(int indek){
        jumlah_saldo=Integer.parseInt(saldo[indek])+jumlah_saldo;
    }
    public void setHasil(String nomer1,int indek,String nama1,String tabungan1,String saldo1){
        nomer[indek] = nomer1;
        nama[indek] = nama1;
        tabungan[indek] = tabungan1;
        saldo[indek] = saldo1;
    }
}
class bank_nasabah extends bank {
    public static void main (String[] args) throws IOException{
        BufferedReader dataIn = new BufferedReader (new InputStreamReader(System.in));
        int count = 0;
        int tanya = 0, total;
        System.out.print("Banyak Data Nasabah : ");
        total=Integer.parseInt(dataIn.readLine());
        System.out.println("__________________________________");
        bank databank = new bank();
        for (int i=0; i < total; i++){
            System.out.println("Data Nasabah Ke-"+(i+1));
            System.out.println("==================================");
            System.out.print("Masukkan No. Rekening : ");
            databank.nomer[i]=dataIn.readLine();
            System.out.print("Nama Nasabah          : ");
            databank.nama[i]=dataIn.readLine();
            System.out.print("Jenis Tabungan [Deposito(input D)/Reguler(input R)] : ");
            databank.tabungan[i]=dataIn.readLine();
            System.out.print("Saldo                 : ");
            databank.saldo[i]=dataIn.readLine();
        }
        for (int i=0; i < total; i++){
            databank.setHasil(databank.nomer[i],i,databank.nama[i],databank.tabungan[i],databank.saldo[i]);
            databank.setJumlah_saldo(i);
        }
        for (int i=0; i < total; i++){
            if (databank.getTabungan(i).equals("D")||databank.getTabungan(i).equals("d")){
                count=count+1;
            }
        }
        System.out.println("\n**************** HASIL DATA NASABAH ****************");
        System.out.println("Jumlah Nasabah Deposito     : "+count);
        System.out.println("Jumlah Nasabah Reguler      : "+(total-count));
        System.out.println("Total Saldo Seluruh Nasabah : "+databank.getJumlah_saldo());
    }
}