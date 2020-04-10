import {getData, Params} from './api'

async function setData() {
  const param: Params = {
    username: 'hylerrix',
    token: 'ningowood',
  }
  const {success, data} = await getData(param)
  console.log('success:', success)
  console.log('data:', data)
}

setData()
