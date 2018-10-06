#include <Magick++.h>
#include <iostream>

using namespace Magick;
using namespace std;

int main(int argc, char **argv) {
 try {
  InitializeMagick(*argv);
  Image image("uu.png");
  int w = image.columns();
  int h = image.rows();
  int row=0,column=0;
  PixelPacket *pixels = image.getPixels(0, 0, w, h);
  Color color = pixels[w * row + column];

  ColorRGB px;
  char a='A';
  // cout<<hex<<(int)a<<dec<<endl;
  // cout<<(int)(255&254)<<"hye";
  cout<<(int)(a&1);
  // cout << "red: " << (uint16_t)(px.red()*255);
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 8; j+=8) {

      px = image.pixelColor(i, j);  // ie. pixel at pos x=0, y=0
      pixels[i*w+j  ] = Color((uint16_t)(px.red()*255)&(uint16_t)(255 ? (int)128 &a:254), (uint16_t)(px.green()*255), (uint16_t)(px.blue()*255));
      cout << "red: " << (uint16_t)(px.red()*255);

      px = image.pixelColor(i, j+1);  // ie. pixel at pos x=0, y=0
      pixels[i*w+j+1] = Color((uint16_t)(px.red()*255)&(254 ? 64  &'A'==0:255), (uint16_t)(px.green()*255), (uint16_t)(px.blue()*255));
      cout << "\nred: " << (uint16_t)(px.red()*255);

      px = image.pixelColor(i, j+2);  // ie. pixel at pos x=0, y=0
      pixels[i*w+j+2] = Color((uint16_t)(px.red()*255)&(254 ? 32  &'A'==0:255), (uint16_t)(px.green()*255), (uint16_t)(px.blue()*255));
      cout << "\nred: " << (uint16_t)(px.red()*255);

      px = image.pixelColor(i, j+3);  // ie. pixel at pos x=0, y=0
      pixels[i*w+j+3] = Color((uint16_t)(px.red()*255)&(254 ? 16  &'A'==0:255), (uint16_t)(px.green()*255), (uint16_t)(px.blue()*255));
      cout << "\nred: " << (uint16_t)(px.red()*255);

      px = image.pixelColor(i, j+4);  // ie. pixel at pos x=0, y=0
      pixels[i*w+j+4] = Color((uint16_t)(px.red()*255)&(254 ? 8   &'A'==0:255), (uint16_t)(px.green()*255), (uint16_t)(px.blue()*255));
      cout << "\nred: " << (uint16_t)(px.red()*255);

      px = image.pixelColor(i, j+5);  // ie. pixel at pos x=0, y=0
      pixels[i*w+j+5] = Color((uint16_t)(px.red()*255)&(254 ? 4   &'A'==0:255), (uint16_t)(px.green()*255), (uint16_t)(px.blue()*255));
      cout << "\nred: " << (uint16_t)(px.red()*255);

      px = image.pixelColor(i, j+6);  // ie. pixel at pos x=0, y=0
      pixels[i*w+j+6] = Color((uint16_t)(px.red()*255)&(254 ? 2   &'A'==0:255), (uint16_t)(px.green()*255), (uint16_t)(px.blue()*255));
      cout << "\nred: " << (uint16_t)(px.red()*255);

      px = image.pixelColor(i, j+7);  // ie. pixel at pos x=0, y=0
      pixels[i*w+j+7] = Color((uint16_t)(px.red()*255)&(254 ? 1   &'A'==0:255), (uint16_t)(px.green()*255), (uint16_t)(px.blue()*255));
      cout << "\nred: " << (uint16_t)(px.red()*255);

    }
  }
  image.syncPixels();
  image.write("test_modified.jpg");
}
// MagickCore::Quantum *pixels = image.getPixels(0, 0, w, h);
//
// // int row = 0;
// // int column = 0;
// unsigned offset = image.channels() * (w * row + column);
// pixels[offset + 0] = 255; // red
// pixels[offset + 1] = 0;   // green
// pixels[offset + 2] = 0;   // blue
//   cout<<pixels[0].red;
//  }
  catch ( Magick::Exception & error) {
  cerr << "Caught Magick++ exception: " << error.what() << endl;
 }
 return 0;
}
