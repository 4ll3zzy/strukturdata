#include <iostream>
#include <algorithm>
using namespace std;

//deklarasi variabel array
#define maxId 2
int id_ml[maxId];
int top = 0;

//deklarasi parameter pointer void header
void header(int *totalpointer, int *myid);

//deklarasi struct
struct Mole{
	int nom;
	int harga;
	int kode;
};

//stack
//fungsi apabila kosong == true true untuk menentukan kondisi pada fungsi display (dingunakan hapus data stack)
bool isEmpty(){
	if(top == 0){
		return true;
	}else{
		return false;
	}
}

//queue
//fungsi apabila penuh == true untuk menentukan kondisi pada fungsi display
bool isFull(){
	if(top >= maxId){
		return true;
	}else{
		return false;
	}
}

//stack & queue
//fungsi display untuk menampilkan apabila ada data maupun tidak ada data
void display(){
	if(!isEmpty()){
		cout << "	Data tersimpan : "<<endl;
		for(int i=0;i<top;i++){
			cout << "	"<< i+1 <<". "<<id_ml[i]<<endl;
		}
	}else{
		cout << "	Data tidak tersedia !"<<endl;
	}
	if(isFull()){
		cout << "	Id Penuh"<<endl;
	}
	cout <<endl;
}

//fungsi untuk menambahkan data 
//queue
void push(){
	if(!isFull()){
		cout << "	Masukkan id : ";
		cin >> id_ml[top];
		top++;
	}
}

//fungsi untuk menghapus data 
//stack
void pop(){
	if(!isEmpty()){
		top--;
	}
}

//sorting
//fungsi mengurutkan berdasarkan nominal (variabel nom)
bool compareByNom(const Mole& a, const Mole& b) {
    return a.nom < b.nom;
}

//searcing
//fungsi untuk mencari data berdasarkan nominal (variabel nom)
void searchByNom(const Mole mole[], int numArr, int targetNom) {
    auto it = std::find_if(mole, mole + numArr, [targetNom](const Mole& m) {
        return m.nom == targetNom;
    });

    if (it != mole + numArr) {
        // Mole ditemukan
        std::cout << "	Data ditemukan = " << it->nom << ", Harga = " << it->harga << ", Kode = " << it->kode << std::endl;
    } else {
        // Mole tidak ditemukan
        std::cout << "	Tidak ada data" << std::endl;
    }
}



int main(){
	
	int kodegame,dm_ml,pil,x,fixId = 0,d,total = 0;
	
	//deklarasi variabel array struct (jumlah data sesuai variabel numArr)
	int numArr = 2;
	Mole mole[numArr] = {
		
		{86, 20000, 1},
		{172, 40000, 2}
		
	};
	
	//sorting
	//memanggil fungsi sort serta fungsi mengurutkan berdasarkan nominal (variabel nom)
	sort(mole, mole + numArr, compareByNom);

	awal :
		
		//system cls digunakan untuk clear screen atau membersihkan layar agar lebih rapi
		system("clear");
		
		//pemanggilan void display atau fungsi display(stack & queue)
		display();
    	cout << "	Pilih id anda terlebih dahulu"<<endl<< "	8. Tambahkan Id " <<endl<<"	9. Hapus id terakhir dibuat"<<endl<<endl<<"	Pilih : ";
    	cin >> pil;
    	
    	//setelah user memilih, akan di masukkan ke variabel pil kemudian di seleksi menggunakan percabangan if else
    	//apabila memasukkan angka 8 akan memasukkan id baru dan kembali ke menu awal
    	//apabila memasukkan angka 9 akan menghapus id terakhir dan kembali ke menu awal
    	//apabila id sudah ada isinya, maka user dapat memasukkan kode 1 untuk menggunakan id ke [0]. kode 2 untuk menggunakan id ke [1] setelah itu ke halaman menu
    	if(pil == 8){
    		push();
    		goto awal;
		}else if(pil == 9){
			pop();
			goto awal;
		}else{
			if(!isEmpty()){
				if(pil == 1){
					fixId = id_ml[0];
					cout << fixId;
					goto menu;
				}else if(pil == 2){
					fixId == id_ml[1];
					cout << fixId;
					goto menu;
				}else{
					goto awal;
				}
				goto menu;
			}else{
				goto awal;
			}
		}
	
	menu :
    
    x = 0;
    system("clear");
    
    //memanggil fungsi header beserta argumen ataupun parameter
    header(&total,&fixId);
    
    cout << "	[1]	Mobile Legends"<<endl<<endl;
    cout << "	Masukkan kode game atau ketik 9 untuk kembali ke pemilihan id"<<endl<<endl;
    cout << "	Pilih Game : ";

    cin >> x;
    cout << endl<<"	==============================\n\n";
    system("clear");
    
    
    //percabangan switch case apabila user memilih 1 akan masuk ke case 1. apablia memilih 2 akan masuk ke case 2. apabila tidak satu pun akan masuk ke default
    switch(x) {
  	case 1:
  		
  		
  		//menggunakan perulangan do while
  		do{
  			x = 0;
  			
  			//memanggil fungsi header kembali
  			header(&total,&fixId);
  			
	  		cout << "	Mobile Legends"<<endl<<endl;
	  		
	  		cout << "	Diurutkan Berdasarkan Nominal : " << endl;
	  		
	  		//sorting
	  		//menggunakan perulangan for dan pointer untuk menampilkan data berdasarkan nominal
    		 for (const Mole& m : mole) {
        		cout << "	" << m.kode << ". " << m.nom << "  " << m.harga << " " << endl;
    		}
	  		cout <<endl<< "	Silahkan masukkan kode Diamond : ";
	  		cin >> dm_ml;
	  		
	  		//setelah user memilih kode diamond. akan diseleksi menggunakan percabangan if, else if, else.
	  		//apabila memilih 1 akan menampilkan data ke [0]
	  		//apabila memilih 2 akan menampilkan data ke [1]
	  		//jika tidak keduanya akan menampilkan tulisan nominal tidak ada dan akan langsung diarahkan untuk mencari data berdasarkan nominal(variabe nom)
	  		if(dm_ml == 1){
	  			
				cout << "	------------------------------"<<endl;
	  			cout << "	Dipilih " << mole[0].nom << " "<< mole[0].harga<<endl;
	  			cout << "	Diamond akan masuk ke id : "<<fixId;
	  			
	  			//pada bagian ini yang semula total == kosong. kemudian akan di isi sesuai harga diamond. berlaku untuk di bawahnya
	  			total = total + mole[0].harga;
	  		}
	  			
			else if(dm_ml == 2){
	  			cout << "	------------------------------"<<endl;
	  			cout << "	Dipilih " << mole[1].nom << " "<< mole[1].harga<<endl;
	  			cout << "	Diamond akan masuk ke id : "<<fixId;
	  			total = total + mole[1].harga;
			  }
			else{
				cout << endl<<endl<<"	------------------------------"<<endl;
				cout << "	Nominal tidak ada"<<endl;
				int targetNom;
    		cout << "	Cari Diamond berdasarkan Nominal : ";
    		cin >> targetNom;
			
			//searci
    		// Melakukan pencarian berdasarkan nom yang diinputkan pengguna
   			searchByNom(mole, numArr, targetNom);
   			
			}
			
			
			cout <<endl<< "	Ketik 8(Ulangi) / 9(Menu Utama) : ";
			cin >> x;
			system("clear");
			
		//dalam perulangan do while apabila user memasukkan angka 8 maka akan mengulangi program di dalam (do) sebanyak 1 kali
		}while(x == 8);
		
		//apabila user memasukkan angka 9 maka akan kembali ke menu
		if (x == 9){
				goto menu;
		}
		cout <<endl<< "	Kode Game Tidak Sesuai"<<endl<<endl;
		cout <<endl<< "	Masukkan angka bebas untuk ke menu utama :";
		cin >> x;
		system("clear");
		goto menu;
  		
    	break;      
    
    //apabila user memasukkan angka 9 pada pemilihan game. maka akan kembali ke pemilihan id
    case 9 :
    	goto awal;

	//apabila user tidak memasukkan kode 1,2,ataupun 9. maka akan muncul pesan di bawah kemudian user memasukkan char bebas akan kembali ke menu
  	default:
  		cout <<endl<< "	Kode Game Tidak Sesuai"<<endl<<endl;
  		cout <<endl<< "	Masukkan input bebas untuk ke menu :";
		cin >> x;
		system("clear");
		goto menu;
	}
    
    return 0;
    
}


//fungsi header untuk menampilkan header beserta total dan juga id menggunakan pointer
void header(int *totalpointer, int *myid) {
    cout << "	==============================\n";
    cout << "	Topup Game" << std::endl;
    cout << "	Id Dipilih : " << *myid << std::endl;
    cout << "	Total Transaksi : " << *totalpointer << std::endl;
    cout << "	==============================\n\n";
}

