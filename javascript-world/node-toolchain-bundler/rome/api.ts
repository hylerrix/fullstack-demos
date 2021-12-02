export interface Params {
  username: string
  token: string
}

export const getData = (params: Params) => Promise.resolve({
  success: true,
  data: 'Hello World!'
})