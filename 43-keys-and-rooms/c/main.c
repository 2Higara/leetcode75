#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// 房间数：roomsSize
// 每个房间的钥匙数：roomsColSize[i]
// 房间：rooms[i]
// 房间是否去过：entered[i]
void enterRoom(int **rooms, int *roomsColSize, int i_room, int *entered) {
  if (entered[i_room] == 0) {
    entered[i_room] = 1;
    for (int i_key = 0; i_key < roomsColSize[i_room]; i_key++) {
      enterRoom(rooms, roomsColSize, rooms[i_room][i_key], entered);
    }
  }
}
bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize) {
  int *entered = (int *)calloc(roomsSize, sizeof(int));
  enterRoom(rooms, roomsColSize, 0, entered);
  for (int i = 0; i < roomsSize; i++)
    if (entered[i] == 0)
      return false;
  return true;
}
