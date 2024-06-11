# :video_game: Caiman
---
![Splash](https://github.com/ImGunHyoeng/temp_caiman/assets/102517991/9ffa218b-43da-461b-8193-88eb298c9e2d)

[![Hits](https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2FImGunHyoeng%2Ftemp_caiman&count_bg=%2379C83D&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=hits&edge_flat=false)](https://hits.seeyoufarm.com)

## 목차
* [개요](#개요)
* [Stacks](#Stacks)
* [게임플레이 방식](#게임플레이-방식)
* [핵심기술](#핵심기술)

## 개요
---
* 개발 기간: 23.09 -24.05
* 멤버구성 : 임건형
* 언리얼을 이용한 액션 RPG입니다.

## 빌드 파일 & 영상링크
---
* 💾  https://drive.google.com/file/d/1-F9IsyQBefgB67ZfxXJkdxqRd_IWR9b8/view?usp=drive_link\

* 🎞  https://youtu.be/HpAkOuOOECc?si=Qpxj_9eoz50Jh-GN



## :books: Stacks
---
### SDK

<img src="https://img.shields.io/badge/unreal engine-0E1128?style=for-the-badge&logo=unreal engine&logoColor=white">
<img src="https://img.shields.io/badge/visual studio-5C2D91?style=for-the-badge&logo=visual studio&logoColor=white">


### Language

<img src="https://img.shields.io/badge/c++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white">


### Version Control

<img src="https://img.shields.io/badge/git-F05032?style=for-the-badge&logo=git&logoColor=white">
<img src="https://img.shields.io/badge/git lfs-F64935?style=for-the-badge&logo=git lfs&logoColor=white">


### :clipboard: Development Log

<img src="https://img.shields.io/badge/notion-000000?style=for-the-badge&logo=notion&logoColor=white">

* 📄 23.9~  23.12 : https://www.notion.so/4fcff93e64464e7f83d84a72745a0cd4?pvs=4
* 📄 24.3 ~ 24.5  : https://www.notion.so/4-1-21bc4eda36ba458cb499190891d6abba?pvs=4


## 게임플레이 방식
---
![-Clipchamp17-ezgif com-optimize](https://github.com/ImGunHyoeng/temp_caiman/assets/102517991/b8137cc6-78bd-4c65-8383-ac77d1d08ac6)
![-Clipchamp17-ezgif com-optimize (1)](https://github.com/ImGunHyoeng/temp_caiman/assets/102517991/7423f48d-1a84-403b-9d7a-b5f7afedd971)

* 조작방법
<img width="428" alt="image" src="https://github.com/ImGunHyoeng/temp_caiman/assets/102517991/768436d2-2128-41d6-b7a4-d54e53ed513e">


* 공격기술 종류
  
|기본공격| 차지어택 | 슈퍼아머차지어택 | 점프어택| 패링 실패 | 패링 성공 |
|:---:|:---:|:---:|:---:|:---:|:---:|
|<img src="https://github.com/ImGunHyoeng/temp_caiman/assets/102517991/9b1903bb-5658-4702-bccf-be0ea636ec5b" width="80%" height="80%">|<img src="https://github.com/ImGunHyoeng/temp_caiman/assets/102517991/4a59eeab-d683-41d0-8544-8358d797342c" width="80%" height="80%">|<img src="https://github.com/ImGunHyoeng/temp_caiman/assets/102517991/2b3216b7-0ac9-4ed0-ba66-ddbbfbcf79b9" width="80%" height="80%">|<img src="https://github.com/ImGunHyoeng/temp_caiman/assets/102517991/21b3ab78-eff6-4e90-a03f-77d2411ba056" width="80%" height="80%">|<img src="https://github.com/ImGunHyoeng/temp_caiman/assets/102517991/572337f0-9fdd-4eed-a61a-33ca0b21a4f4" width="80%" height="80%">|<img src="https://github.com/ImGunHyoeng/temp_caiman/assets/102517991/c898878a-3d1a-4d4a-914b-2483d7fc5947" width="80%" height="80%">|
|기본적인 공격으로 이단공격|차지를 통해서 공격한다|공격을 받아도 취소되지 않으며 데미지는 일반 차지공격보다는 낮음|점프해서 공격한다|패링 시전도중에 공격을 받지 않으면 이렇게 된다|패링도중에 공격을 받으면 이렇게 된다|




## 핵심기술
---

자연스러운 플레이어 움직임: HFSM (Hierarchical Finite State Machine) 기술을 사용하여 상황에 따라서 플레이어의 피격판정이 다르게 하였습니다.

똑똑한 적 AI: BT (Behavior Tree) 기술을 통해 적 캐릭터의 행동을 상황에 맞게 선택해서 행동하도록 구성하였습니다.

아이템과 인벤토리: DataTable을 활용하여 아이템과 인벤토리 시스템을 구축했습니다.

다양한 애니메이션: Animation Retargeting 기술을 사용하여 캐릭터에 다양한 애니메이션이 적용되도록 하였습니다.
