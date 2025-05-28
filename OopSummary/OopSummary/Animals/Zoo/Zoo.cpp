#include "Zoo.h"
#include <random>

using namespace std;

/**
 * @brief Zoo 클래스 생성자
 * 
 * 동물 포인터 배열을 모두 nullptr로 초기화하여
 * 아직 동물이 추가되지 않은 상태로 만듭니다.
 */
Zoo::Zoo() {
  animals.fill(nullptr);
}

/**
 * @brief Zoo에 새로운 동물을 추가하는 함수
 * 
 * 전달된 Animal 포인터를 배열 내 빈 슬롯에 저장합니다.
 * 만약 빈 슬롯이 없으면 경고 메시지를 출력합니다.
 * 
 * @param animal 추가할 Animal 객체의 포인터
 */
void Zoo::addAnimal(std::shared_ptr<Animal> animal) {
  // unique_ptr -> 서버쪽에선 종종사용. -> 아이템 복사 방지
  for (size_t i = 0; i < animals.size(); ++i) {
    if (animals[i] == nullptr) {
      animals[i] = animal;
      return;
    }
  }
  std::cout << "더 이상 동물을 추가할 수 없습니다." << '\n';
}

/**
 * @brief Zoo에 추가된 모든 동물들의 행동 수행
 * 
 * 배열에 저장된 모든 동물 객체의 makeSound() 함수를 호출하여
 * 각 동물이 소리를 내도록 합니다.
 */
void Zoo::performActions() {
  for (auto animal : animals) {
    if (animal != nullptr) {
      animal->makeSound();
    }
  }
}

Animal* Zoo::createRandomAnimal()
{
  random_device randomDevice;  // 난수 생성기 초기화
  mt19937 restEngine(randomDevice()); // Mersenne Twister 엔진 초기화
  uniform_int_distribution<> dist(0, 2); // 0부터 2까지 균등 분포

  int random_number = dist(restEngine);

  // std::shared_ptr<Animal>는 포인터가 아니라 스마트 포인터 객체이고, Animal* 포인터를 얻으려면 .get() 멤버 함수를 사용해야 함
  return animals[random_number].get();
}
