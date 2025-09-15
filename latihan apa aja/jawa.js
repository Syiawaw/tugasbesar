console.log("tes")


title=document.title
    title='Jawaaa sekrip'
document.title=title
body=document.body
    body.style.backgroundColor = 'pink'
        body.append('ini coba')
        //h2baru =document.createElement('p')
        //h2baru.innerText="ini coba2"
        //body.append(h2baru)

h1 = document.getElementById('judul')
h1.style.color ="red";
listH2 = document.getElementsByTagName('h2')
listH2[1].innerText = 'getooot'
makanan = document.getElementsByClassName('makanan')
    for(let i =0; i < makanan.length; i++)
        {
            makanan[i].style.color = "blue"

        }
        barang = document.getElementsByClassName('barang')
            for(let j =0; j < barang.length; j++)
            { 
                barang[j].style.color = "red"
         }
        