#include "TileMap.h"
#include <iostream>

TileMap::TileMap(int mapWidth,int mapHeight,int mapDepth,TileSet* tileSet){

    int i;

    this->mapWidth = mapWidth;
    this->mapHeight = mapHeight;
    this->mapDepth = mapDepth;
    this->tileSet = tileSet;

    tileMatrix.assign(mapWidth*mapHeight*mapDepth, -1);
}

TileMap::TileMap(const std::string& file,TileSet* tileSet){

    this->tileSet = tileSet;
    load(file);
}

void TileMap::load(const std::string& file){

}

void TileMap::setTileSet(TileSet* tileSet){
    this->tileSet = tileSet;
}

int& TileMap::at(int x,int y,int z){
    return tileMatrix[x + y*mapWidth + z*mapWidth*mapHeight];
}

void TileMap::render(int cameraX,int cameraY){

    int i;
    for(i=0;i<mapDepth;i++){
        renderLayer(i,cameraX,cameraY);
    }
}

void TileMap::renderLayer(int layer,int cameraX,int cameraY){

    int i,j;


    for(i=0;i<mapHeight;i++){
        for (j=0;j<mapWidth;j++){
            tileSet->render(at(i,j,layer),i*tileSet->getTileWidth() - cameraX,j*tileSet->getTileHeight() - cameraY);
        }
    }
}

int TileMap::getWidth(){
    return this->mapWidth;
}

int TileMap::getHeight(){
    return this->mapHeight;
}
int TileMap::getDepth(){
    return this->mapDepth;
}


