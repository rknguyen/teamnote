string S = "Xin chao tat ca cac ban"; // Khởi tạo giá trị của xâu
stringstream ss(S); // Khởi tạo stringstream từ xâu S

while (ss >> token) { // Đọc lần lượt các phần của xâu. Các phần tách nhau bởi dấu cách hoặc xuống dòng.
  cout << token << endl;
}
