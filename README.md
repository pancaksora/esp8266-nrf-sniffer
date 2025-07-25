# 📡 PancakSora Sniff

**LoRa Packet Sniffer Firmware** for LilyGo T3 V1.6.1 + OLED

> Mendeteksi, merekam, dan menampilkan semua aktivitas LoRa di udara secara real-time — cocok untuk debugging, eksplorasi, dan pembelajaran!

---

## 🚀 Fitur
- ✅ Tangkap semua paket LoRa di frekuensi 915 MHz
- 🛰️ Tampilkan data RSSI, SNR, dan jumlah paket di OLED 0.96"
- 🔍 Cocok untuk eksplorasi Meshtastic & perangkat LoRa lain
- ⚡ Dibuat untuk board LilyGo T3 V1.6.1 (ESP32 + SX1276 + OLED)

---

## 📷 Tampilan

<img src="https://user-images.githubusercontent.com/your-firmware-preview.png" width="350"/>

---

## 📦 Persiapan

### Hardware:
- LilyGo LoRa T3 V1.6.1
- USB-C cable
- (Opsional) Powerbank untuk operasi mobile

### Software:
- [PlatformIO + VS Code](https://platformio.org/)
- Atau gunakan Arduino IDE (konversi manual)

---

## 🧠 Konfigurasi LoRa (bisa disesuaikan):
```cpp
LoRa.setSpreadingFactor(7);
LoRa.setSignalBandwidth(125E3);
LoRa.setCodingRate4(5);
LoRa.begin(915E6);
Sesuaikan frekuensi (433E6, 868E6, atau 915E6) sesuai wilayahmu

📂 Instalasi & Upload
Clone repo ini: git clone https://github.com/pancaksora/pancaksora-sniff.git
Buka dengan VS Code + PlatformIO
Sambungkan board
Klik Upload
Buka Serial Monitor (115200 baud)
Cek OLED untuk tampilan real-time

🛡️ Catatan Penting
🔐 Sniffer ini tidak dapat membaca isi paket terenkripsi (seperti AES Meshtastic)
🎯 Tujuan utama adalah deteksi dan logging sinyal LoRa, bukan decoding payload
⚡ Firmware ini cocok untuk eksplorasi sinyal, debugging mesh, dan pengamatan frekuensi

🙌 Credits
Firmware ini dikembangkan oleh Ali Muhsi Kemal (PancakSora) sambil ngopi malam-malam ☕🤖
