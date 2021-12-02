import { BlitzApiHandler } from "blitz"

const handler: BlitzApiHandler = async (req, res) => {
  const {
    query: { name }
  } = req

  res.statusCode = 200
  res.setHeader("Content-Type", "application/json")
  res.end(JSON.stringify({ hello: name }))
}

export default handler
